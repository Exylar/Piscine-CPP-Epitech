/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** new
*/

#include "new.h"
#include "raise.h"

Object *new(const Class *class, ...)
{
    va_list args;

    va_start(args, class);
    return (va_new(class, &args));
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj;

    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Fail Malloc");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return obj;
}

void delete(Object *ptr)
{
    Class *class;

    class = ptr;
    if (class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
}
