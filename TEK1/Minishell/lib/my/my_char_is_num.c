/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_char_is_num
*/

#include "../../include/my.h"

int my_char_is_num(char car)
{
    if (car < '0' || car > '9')
        return 0;
    return 1;
}
