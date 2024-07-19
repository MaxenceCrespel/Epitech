/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** my_ls
*/

#include "include/my_printf.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}
