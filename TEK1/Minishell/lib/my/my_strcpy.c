/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char *my_strcpy(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src));
    int a = 0;

    while (a < my_strlen(src)) {
        dest[a] = src[a];
        a++;
    }
    return dest;
}
