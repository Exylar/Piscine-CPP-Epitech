/*
** EPITECH PROJECT, 2019
** cpp_rush1_2019
** File description:
** int.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "float.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class base;
    float num;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->num = va_arg(*args, double);
    va_end(*args);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    size_t needed = snprintf(NULL, 0, "<Float (%f)>", this->num) + 1;
    char *buffer = malloc(needed);

    if (buffer == NULL)
        raise("Fail Malloc");
    sprintf(buffer, "<Float (%f)>", this->num);
    return buffer;
}

static FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    FloatClass *res = new(Float, this->num + other->num);

    return (res);
}

static FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    FloatClass *res = new(Float, this->num - other->num);

    return (res);
}

static FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    FloatClass *res = new(Float, this->num * other->num);

    return (res);
}

static FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    FloatClass *res = new(Float);

    if (other->num == 0.0)
        raise("Div by 0");
    res->num = this->num / other->num;
    return (res);
}

static bool Float_equal(const FloatClass *this, const FloatClass *other)
{
    return (this->num == other->num) ? 1 : 0;
}

static bool Float_greater(const FloatClass *this, const FloatClass *other)
{
    return (this->num > other->num) ? 1 : 0;
}

static bool Float_lower(const FloatClass *this, const FloatClass *other)
{
    return (this->num < other->num) ? 1 : 0;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_equal,
        .__gt__ = (binary_comparator_t)&Float_greater,
        .__lt__ = (binary_comparator_t)&Float_lower,
    },
    .num = 0
};

const Class *Float = (const Class *)&_description;
