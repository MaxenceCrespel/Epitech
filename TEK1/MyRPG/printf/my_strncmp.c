/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** lib
*/

#include "include/my_printf.h"

int my_strncmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0' )
        i++;
    return (s1[i] == '=' && s2[i] == '\0');
}
