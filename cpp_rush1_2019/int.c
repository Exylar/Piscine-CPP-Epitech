/*
** EPITECH PROJECT, 2019
** cpp_rush1_2019
** File description:
** int.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "int.h"
#include "raise.h"
#include "new.h"

typedef struct
{
    Class base;
    int num;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->num = va_arg(*args, int);
    va_end(*args);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    size_t needed = snprintf(NULL, 0, "<Int (%d)>", this->num) + 1;
    char *buffer = malloc(needed);

    if (buffer == NULL)
        raise("Fail Malloc");
    sprintf(buffer, "<Int (%d)>", this->num);
    return buffer;
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    IntClass *res = new(Int);

    res->num = this->num + other->num;
    return (res);
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    IntClass *res = new(Int);

    res->num = this->num - other->num;
    return (res);
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    IntClass *res = new(Int, this->num * other->num);

    return (res);
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    IntClass *res;

    if (other->num == 0)
        raise("Div by 0");
    res = new(Int, this->num / other->num);
    return (res);
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    return (this->num == other->num);
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    return (this->num > other->num);
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    return (this->num < other->num);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .num = 0
};

const Class *Int = (const Class *)&_description;
