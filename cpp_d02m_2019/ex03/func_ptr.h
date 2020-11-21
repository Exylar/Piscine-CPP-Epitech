/*
** EPITECH PROJECT, 2019
** cpp_d02m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef CPP_D02M_2019_FUNC_PTR_H
#define CPP_D02M_2019_FUNC_PTR_H

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);

typedef enum action_e
{
    PRINT_NORMAL,
    PRINT_REVERSE,
    PRINT_UPPER,
    PRINT_42
}   action_t;

typedef struct ptr_fun_s {
    action_t type;
    void *(*fct)(const char*);
} ptr_fun_t;

void do_action(action_t action, const char *str);

#endif //CPP_D02M_2019_FUNC_PTR_H
