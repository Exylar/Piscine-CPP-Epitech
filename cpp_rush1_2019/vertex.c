/*
** EPITECH PROJECT, 2019
** cpp_rush1_2019
** File description:
** vertex.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "vertex.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
    va_end(*args);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = NULL;
    size_t needs = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>",
    this->x, this->y, this->z) + 1;

    str = malloc(needs);
    if (!str)
        raise("Fail Malloc");
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

static VertexClass *Vertex_add(const VertexClass *this,
const VertexClass *other)
{
    VertexClass *new_vertex_add;

    new_vertex_add = new(Vertex, this->x + other->x, this->y + other->y,
    this->z + other->z);
    return (new_vertex_add);
}

static VertexClass *Vertex_sub(const VertexClass *this,
const VertexClass *other)
{
    VertexClass *new_vertex_sub;

    new_vertex_sub = new(Vertex, this->x - other->x, this->y - other->y,
    this->z - other->z);
    return (new_vertex_sub);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;