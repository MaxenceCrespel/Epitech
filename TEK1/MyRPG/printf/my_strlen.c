/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** task01
*/

#include "include/my_printf.h"

int my_strlen(char const *str)
{
    int c = 0;

    while (str[c] != '\0') {
        c++;
    }
    return (c);
}
