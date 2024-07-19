/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** flag
*/

#include "../../include/my.h"

int clean(const char *str, int a)
{
    int espace = 0;

    a++;
    while ((str[a] == '-' || str[a] == ' ')
    && (str[a + 1] < '0' || str[a + 1] > '9')) {
        if (espace == 0 && str[a] == ' ')
            espace = 1;
        a++;
    }
    for (int b = a; (str[b] >= 'a' && str[b] <= 'z')
    || (str[b] >= 'A' && str[b] <= 'Z'); b++)
        if (espace == 1 && (str[a] == 'd' || str[a] == 'i'))
            my_putchar(' ');
    return a;
}

int hashtag(const char *str, va_list ap, int a)
{
    while (str[a + 1] == '-' || str[a + 1] == ' ' || str[a + 1] == '#')
        a++;
    switch (str[a + 1]) {
        case 'x':
            my_putstr("0x");
            hexadecimal(va_arg(ap, int), 'a');
            a++;
            break;
        case 'X':
            my_putstr("0X");
            hexadecimal(va_arg(ap, int), 'A');
            a++;
            break;
        case 'o':
            my_putchar('0');
            octal(va_arg(ap, int));
            a++;
            break;
    }
    return a;
}

void flag_bis(const char *str, va_list ap, int a)
{
    switch (str[a]) {
        case 'x':
            hexadecimal(va_arg(ap, int), 'a');
            break;
        case 'X':
            hexadecimal(va_arg(ap, int), 'A');
            break;
        case 'u':
            my_put_unsigned_nbr(va_arg(ap, unsigned int));
            break;
        case 'b':
            binary(va_arg(ap, int));
            break;
        case '%':
            my_putchar('%');
            break;
        case 'h':
            my_put_short(va_arg(ap, int));
            break;
    }
}

void flag(const char *str, va_list ap, int a)
{
    switch (str[a]) {
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'o':
            octal(va_arg(ap, int));
            break;
    }
}
