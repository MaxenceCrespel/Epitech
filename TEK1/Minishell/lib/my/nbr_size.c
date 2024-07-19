/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** nbr_size
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/my.h"

int nbr_size(va_list second)
{
    int a = 0;
    int nbr = va_arg(second, int);
    char *str = malloc(sizeof(char) * 15);

    int_to_str(str, nbr);
    while (str[a] != '\0')
        a++;
    return a;
}
