/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** lib
*/

#include "include/my_printf.h"

char *my_strcpy(char *dest, char *src)
{
    int i;
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
