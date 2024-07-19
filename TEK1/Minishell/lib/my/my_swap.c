/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int stock = *a;
    *a = *b;
    *b = stock;
}
