/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** lib
*/

#include "include/my_printf.h"

int my_str_isnum(char *str)
{
    int i = 0;
    for (; str[i]; i++) {
        if (str[i] <= '9' && str[i] >= '0')
            continue;
        else
            return 0;
    }
    return 1;
}
