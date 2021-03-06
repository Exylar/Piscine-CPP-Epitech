/*
** EPITECH PROJECT, 2019
** cpp_d03_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/
#ifndef CPP_D03_2019_STRING_H
#define CPP_D03_2019_STRING_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct string_s {
    char *str;
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*assign_c)(struct string_s *this, const char *s);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    void (*clear)(struct string_s *this);
    int (*size)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *str);
    int (*compare_c)(const struct string_s *this, const char *str);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_s *this);
    int (*empty)(const struct string_s *this);
    int (*find_s)(const struct string_s *this,
    const struct string_s *str, size_t pos);
    int (*find_c)(const struct string_s *this, const char *str, size_t pos);
    void (*insert_c)(struct string_s *this, size_t pos, const char *str);
    void (*insert_s)(struct string_s *this, size_t pos,
    const struct string_s *str);
    int (*to_int)(const struct string_s *this);
    struct string_s **(*split_s)(const struct string_s *this, char separator);
    char **(*split_c)(const struct string_s *this, char separator);
    void (*print)(const struct string_s *this);
    void (*join_c)(struct string_s *this, char delim, const char * const * tab);
    void (*join_s)(struct string_s *this, char delim,
    const struct string_s * const * tab);
    struct string_s *(*substr)(const struct string_s *this,
    int offset, int length);
} string_t;

char *strcat(char *dest, const char *src);
char *stpcpy(char *dest, const char *src);
char *strdup(const char *s);
size_t strlen(const char *s);
int strcmp(const char *s1, const char *s2);
void *memset(void *s, int c, size_t n);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *s, const char *delim);
char *index(const char *s, int c);
void string_init(string_t *this, const char *str);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);;
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);
void print(const string_t *this);
void join_c(string_t *this, char delim, const char * const * tab);
void join_s(string_t *this, char delim, const string_t * const * tab);
string_t *substr(const string_t *this, int offset, int length);

#endif //CPP_D03_2019_STRING_H