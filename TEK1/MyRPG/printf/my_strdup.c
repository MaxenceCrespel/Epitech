/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_ls
*/

#include "include/my_printf.h"

char *my_strdup(char *str)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    while (str[i]) {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = 0;
    return cpy;
}
