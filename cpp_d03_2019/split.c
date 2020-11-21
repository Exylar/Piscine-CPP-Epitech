/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "string.h"

string_t **split_s(const string_t *this, char separator)
{
    char delim[2];
    delim[0] = separator;
    delim[1] = '\0';
    string_t **array_string_t_split = NULL;
    char *token;

    if (!this || !this->str)
        return NULL;
    token = strtok(this->str, delim);
    for (int i = 0; token != NULL; i++) {
        array_string_t_split = realloc(array_string_t_split,
        sizeof(string_t *) * (i + 2));
        array_string_t_split[i] = malloc(sizeof(string_t));
        string_init(array_string_t_split[i], token);
        array_string_t_split[i + 1] = NULL;
        token = strtok(NULL, delim);
    }
    return array_string_t_split;
}

char **split_c(const string_t *this, char separator)
{
    char delim[2];
    delim[0] = separator;
    delim[1] = '\0';
    char **array_split = malloc(sizeof(char *));
    array_split[0] = NULL;
    char *token = strtok(this->str, delim);

    for (int i = 0; token != NULL; i++) {
        array_split = realloc(array_split, sizeof(char *) * (i + 2));
        array_split[i] = strdup(token);
        array_split[i + 1] = NULL;
        token = strtok(NULL, delim);
    }
    return array_split;
}