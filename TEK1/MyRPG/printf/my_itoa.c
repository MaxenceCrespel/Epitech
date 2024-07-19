/*
** EPITECH PROJECT, 2022
** my_itoa
** File description:
** lib
*/

#include "include/my_printf.h"

char *my_itoa_neg(int nb)
{
    nb = nb * (-1);
    int i = 0;
    char *result;
    int dc = 0;
    int len = 1;
    int n = nb;
    for (; n != 0; n /= 10)
        len++;
    result = malloc(len + 2);
    for (; i < len; i++) {
        dc = nb % 10;
        nb = nb / 10;
        result[len - (i + 1)] = dc + '0';
    }
    result[len] = '\0';
    result[0] = '-';
    return (result);
}

char *my_itoa(int nb)
{
    int i = 0;
    char *result;
    int dc = 0;
    int len = 0;
    int n = nb;
    if (nb < 0)
        return my_itoa_neg(nb);
    if (nb == 0)
        return (my_strdup("0"));
    for (; n != 0; n /= 10)
        len++;
    result = malloc(len + 1);
    for (; i < len; i++) {
        dc = nb % 10;
        nb = nb / 10;
        result[len - (i + 1)] = dc + '0';
    }
    result[len] = '\0';
    return (result);
}
