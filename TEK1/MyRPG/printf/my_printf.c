/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include "include/my_printf.h"

void my_printf(char *str, ...)
{
    unsigned int i;

    va_list arg;
    va_start(arg, str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i++;
            which_modulo(str, arg, i);
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(arg);
}
