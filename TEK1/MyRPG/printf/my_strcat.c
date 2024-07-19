/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** stumper
*/

#include "include/my_printf.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;
    char *new;

    new = malloc(sizeof(*new) * (my_strlen(dest) + my_strlen(src) + 1));
    for (; dest[i]; i++)
        new[i] = dest[i];
    for (; src[count]; count++)
        new[i + count] = src[count];
    new[i + count] = '\0';
    return (new);
}
