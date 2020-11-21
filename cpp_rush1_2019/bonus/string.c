/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** char
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "char.h"
#include "string_bonus.h"
#include "new.h"
#include "raise.h"
#include <string.h>

typedef struct
{
    Class base;
    char *str;
} StringClass;

static void String_ctor(StringClass *this, va_list *args)
{
    this->str = va_arg(*args, char *);
    va_end(*args);
}

static void String_dtor(StringClass *this)
{
    (void)this;
}

static char *String_str(StringClass *this)
{
    size_t needed = snprintf(NULL, 0, "<String (%s)>", this->str) + 1;
    char *buffer = malloc(needed);

    if (buffer == NULL)
        raise("Fail Malloc");
    sprintf(buffer, "<String (%s)>", this->str);
    return buffer;
}

static StringClass *String_add(const StringClass *this, const StringClass *other)
{
    StringClass *res = new(String);
    char *buffer = malloc(sizeof(char) * strlen(this->str) + strlen(other->str) + 1);

    strcpy(buffer, this->str);
    res->str = strdup(strcat(buffer, other->str));
    free(buffer);
    return (res);
}

static const StringClass _description = {
    {
        .__size__ = sizeof(StringClass),
        .__name__ = "String",
        .__ctor__ = (ctor_t)&String_ctor,
        .__dtor__ = (dtor_t)&String_dtor,
        .__str__ = (to_string_t)&String_str,
        .__add__ = (binary_operator_t)&String_add,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .str = 0
};

const Class *String = (const Class *)&_description;
