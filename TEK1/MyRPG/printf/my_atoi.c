/*
** EPITECH PROJECT, 2022
** my_atoi
** File description:
** lib
*/

#include "include/my_printf.h"

int my_atoi(char *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    if (str[0] == '-') {
        neg = -1;
        i++;
    }
    while (str[i]) {
        nb = nb * 10;
        nb += str[i] - '0';
        i++;
    }
    return (nb * neg);
}
