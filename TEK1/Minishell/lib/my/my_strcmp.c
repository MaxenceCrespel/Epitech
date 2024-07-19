/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int compare_char(char const *s1, char const *s2)
{
    int index = 0;

    for (; s1[index] != '\0'; index++)
        if (s1[index] != s2[index])
            return 0;
    return 1;
}

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) == my_strlen(s2))
        if (compare_char(s1, s2) == 1)
            return 1;
    return 0;
}
