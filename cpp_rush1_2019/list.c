/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** list.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "int.h"
#include "raise.h"
#include "new.h"
#include "object.h"
#include "new.h"
#include "list.h"
#include "container.h"

typedef struct list_s {
    Object *obj;
    struct list_s *next;
} list_t;

typedef struct
{
    Container base;
    Class *_type;
    size_t _size;
    list_t *_chained_list;
} ListClass;

typedef struct {
    Iterator base;
    ListClass *_list;
    size_t _idx;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
}

static bool ListIterator_eq(ListIteratorClass *this,
ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool ListIterator_gt(ListIteratorClass *this,
ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(ListIteratorClass *this,
ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    list_t *save;
    list_t *return_node;

    if (this->_idx >= this->_list->_size)
        raise("Out of range");
    save = this->_list->_chained_list;
    for (size_t i = 0; i < this->_idx; i++)
        this->_list->_chained_list = this->_list->_chained_list->next;
    return_node = this->_list->_chained_list;
    this->_list->_chained_list = save;
    return (return_node->obj);
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    list_t *save;
    va_list args;

    va_start(args, this);
    if (this->_idx >= this->_list->_size)
        raise("Invalid index");
    save = this->_list->_chained_list;
    for (size_t i = 0; i < this->_idx; i++)
        this->_list->_chained_list = this->_list->_chained_list->next;
    this->_list->_chained_list = save;
    delete(this->_list->_chained_list->obj);
    this->_list->_chained_list->obj = va_new(this->_list->_type, &args);
    this->_list->_chained_list = save;
    va_end(args);
}

static const ListIteratorClass ListIteratorDescr = {
    {
        {
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._idx = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static void List_ctor_loop(ListClass *this, list_t *save, va_list *args)
{
    list_t *node;
    va_list list;

    for (size_t i = 1; i < this->_size; i++) {
        va_copy(list, *args);
        node = malloc(sizeof(list_t));
        if (node == NULL)
            raise("Fail Malloc");
        node->obj = va_new(this->_type, &list);
        va_end(list);
        node->next = NULL;
        this->_chained_list->next = node;
        this->_chained_list = node;
    }
    this->_chained_list = save;
}

static void List_ctor(ListClass *this, va_list *args)
{
    list_t *save = NULL;
    va_list list;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    va_copy(list, *args);
    this->_chained_list = NULL;
    if (this->_size == 0)
        return;
    this->_chained_list = malloc(sizeof(list_t));
    if (this->_chained_list == NULL)
        raise("Fail Malloc");
    this->_chained_list->obj = va_new(this->_type, &list);
    va_end(list);
    this->_chained_list->next = NULL;
    save = this->_chained_list;
    List_ctor_loop(this, save, args);
}

static void List_dtor(ListClass *this)
{
    list_t *save;

    for (size_t i = 0; i < this->_size; i++) {
        save = this->_chained_list->next;
        delete(this->_chained_list->obj);
        free(this->_chained_list);
        this->_chained_list = save;
    }
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this, this->_size));
}

static Object *List_getitem(ListClass *this, ...)
{
    list_t *save;
    list_t *return_node;
    va_list args;
    size_t size;

    va_start(args, this);
    size = va_arg(args, size_t);
    if (size >= this->_size)
        raise("Invalid index");
    save = this->_chained_list;
    for (size_t i = 0; i < size; i++)
        this->_chained_list = this->_chained_list->next;
    return_node = this->_chained_list;
    this->_chained_list = save;
    return return_node->obj;
}

static void List_setitem(ListClass *this, ...)
{
    list_t *save;
    va_list args;
    size_t size;

    va_start(args, this);
    size = va_arg(args, size_t);
    if (size >= this->_size)
        raise("Invalid index");
    save = this->_chained_list;
    for (size_t i = 0; i < size; i++)
        this->_chained_list = this->_chained_list->next;
    delete(this->_chained_list->obj);
    this->_chained_list->obj = va_new(this->_type, &args);
    this->_chained_list = save;
    va_end(args);
}

static const ListClass _descr = {
    {
        {
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._chained_list = NULL
};

const Class *List = (const Class *)&_descr;