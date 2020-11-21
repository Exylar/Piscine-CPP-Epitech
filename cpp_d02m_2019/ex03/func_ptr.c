/*
** EPITECH PROJECT, 2019
** cpp_d02m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "func_ptr.h"
#include <stdio.h>
#include <string.h>

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *copy_str = strdup(str);
    int length = strlen(copy_str);
    char memory;

    for (int i = 0; i < length / 2; i++) {
        memory = *(copy_str + i);
        *(copy_str + i) = *(str + length - i - 1);
        *(copy_str + length - i - 1) = memory;
    }
    printf("%s\n", copy_str);
}

void print_upper(const char *str)
{
    char *copy_str = strdup(str);

    for (int i = 0; copy_str[i] != '\0'; i++) {
        if (copy_str[i] >= 97 && copy_str[i] <= 122)
            copy_str[i] = copy_str[i] - 32;
    }
    printf("%s\n", copy_str);
}

void print_42(const char *str)
{
    str = str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    ptr_fun_t my_func[] = {
            {0, (void *)&print_normal},
            {1, (void *)&print_reverse},
            {2, (void *)&print_upper},
            {3, (void *)&print_42},
    };

    for (int i = 0; i < 4; i++) {
        if (my_func[i].type == action) {
            my_func[i].fct(str);
        }
    }
}