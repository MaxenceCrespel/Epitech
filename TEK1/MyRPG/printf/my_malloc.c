/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** lib
*/

#include "include/my_printf.h"

char *my_malloc(int len)
{
    char *str = malloc(sizeof(char) * len + 1);
    if (str == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        str[i] = '\0';
    return str;
}
