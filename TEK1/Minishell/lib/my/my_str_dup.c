/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_str_dup
*/

#include "../../include/my.h"

char *my_str_dup(char *str)
{
    int a = my_strlen(str);
    int b = 0;
    char *dest = malloc(sizeof(char) * a + 1);

    for (; b < a; b++)
        dest[b] = str[b];
    dest[b] = '\0';
    return dest;
}
