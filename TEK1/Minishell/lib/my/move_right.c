/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** move_right
*/

#include "../../include/my.h"

void move_right(char *str)
{
    int a = my_strlen(str);

    while (a > 0) {
        str[a] = str[a - 1];
        a--;
    }
}
