/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include "point.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    va_end(*args);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    size_t needed = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y) +
    1;
    char *buffer = malloc(needed);

    if (buffer == NULL)
        raise("Fail Malloc");
    sprintf(buffer, "<Point (%d, %d)>", this->x, this->y);
    return buffer;
}

static PointClass *Point_add(const PointClass *this, const PointClass *other)
{
    int x = this->x + other->x;
    int y = this->y + other->y;
    PointClass *new_obj = new(Point, x, y);

    return new_obj;
}

static PointClass *Point_sub(const PointClass *this, const PointClass *other)
{
    PointClass *new_point_sub;

    new_point_sub = new(Point, this->x - other->x, this->y - other->y);
    return (new_point_sub);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
