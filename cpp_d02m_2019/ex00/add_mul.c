/*
** EPITECH PROJECT, 2019
** cpp_d02m_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    sum[0] = first + second;
    product[0] = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int save = first[0];

    first[0] = first[0] + second[0];
    second[0] = save * second[0];
}