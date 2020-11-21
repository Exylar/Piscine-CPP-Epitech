/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** char
*/

#include <stdarg.h>
#include <stdio.h>
#include "char.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class base;
    char c;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
    va_end(*args);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    size_t needed = snprintf(NULL, 0, "<Char (%c)>", this->c) + 1;
    char *buffer = malloc(needed);

    if (buffer == NULL)
        raise("Fail Malloc");
    sprintf(buffer, "<Char (%c)>", this->c);
    return buffer;
}

static CharClass *Char_add(const CharClass *this, const CharClass *other)
{
    CharClass *new_Char_sub;

    new_Char_sub = new(Char, this->c + other->c);
    return (new_Char_sub);
}

static CharClass *Char_sub(const CharClass *this, const CharClass *other)
{
    CharClass *new_Char_sub;

    new_Char_sub = new(Char, this->c - other->c);
    return (new_Char_sub);
}

static CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    CharClass *res = new(Char, this->c * other->c);

    return (res);
}

static CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    CharClass *res;

    if (other->c == 0)
        raise("Div by 0");
    res = new(Char, this->c / other->c);
    return (res);
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    return (this->c == other->c);
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    return (this->c > other->c);
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    return (this->c < other->c);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class *Char = (const Class *)&_description;
