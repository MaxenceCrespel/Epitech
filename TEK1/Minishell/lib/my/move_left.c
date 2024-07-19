/*
** EPITECH PROJECT, 2021
** move_left.c
** File description:
** move_left
*/

#include "../../include/my.h"

void move_left(char *res, int nb)
{
    int a = 0;

    for (; nb < my_strlen(res); nb++)
        res[nb] = res[nb + 1];
    res[nb] = '\0';
}
