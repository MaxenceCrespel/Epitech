/*
** EPITECH PROJECT, 2022
** my_strlow
** File description:
** lib
*/

#include "include/my_printf.h"

char *my_strlow(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] += 32;
    return (str);
}
