/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_atoi
*/

#include "../../include/my.h"

int my_atoi(char *str)
{
    int a = 0;
    int negatif = 1;
    int res = 0;

    if (str[0] == '-') {
        negatif = -1;
        a = 1;
    }
    for (; str[a] != '\0'; a++)
        res = res * 10 + (str[a] - 48);
    return (res * negatif);
}
