/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcut
*/

#include <stdlib.h>
#include "../../include/my.h"

char *strcut(char *src, int start, int end)
{
    int a = 0;
    char *str = malloc(sizeof(char) * (end - start) + 1);

    while (start < end) {
        str[a] = src[start];
        start++;
        a++;
    }
    str[a] = '\0';
    return str;
}
