/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "ex00.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

static void cthulhu_initialize(cthulhu_t *this)
{
    printf("----\n");
    this->m_power = 42;
    if (this->m_name != NULL)
        free(this->m_name);
    this->m_name = strdup("Cthulhu");
    printf("Building %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new_element = malloc(sizeof(cthulhu_t));
    cthulhu_initialize(new_element);
    return new_element;
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    cthulhu_t *new_ele = new_cthulhu();
    this->m_parent = *new_ele;
    if (!_is_A_Legend)
        this->m_parent.m_power = 0;
    if (this->m_parent.m_name != NULL)
        free(this->m_parent.m_name);
    this->m_parent.m_name = strdup(_name);
    this->m_is_a_legend = _is_A_Legend;
    printf("Building %s\n", this->m_parent.m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new_koala = malloc(sizeof(koala_t));
    koala_initializer(new_koala, name, is_a_legend);
    return new_koala;
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power = this->m_power - 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    this->m_power = this->m_power + 42000;
    printf("%s sleeps\n", this->m_name);
}


void eat(koala_t *this)
{
    this->m_parent.m_power = this->m_parent.m_power + 42;
    printf("%s eats\n", this->m_parent.m_name);
}