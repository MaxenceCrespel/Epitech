/*
** EPITECH PROJECT, 2022
** printf_double_tab
** File description:
** lib
*/

#include "include/my_printf.h"

void printf_double_tab(char **arg)
{
    for (int i = 0; arg[i]; i++) {
        my_printf("%s", arg[i]);
        my_putchar('\n');
    }
}
