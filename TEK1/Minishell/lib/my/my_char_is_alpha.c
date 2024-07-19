/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_char_is_alpha
*/

#include "../../include/my.h"

int my_char_is_alpha(char car)
{
    if (car < 65 || (car > 90 && car < 97) || car > 122)
        return 0;
    return 1;
}
