/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_printf
*/

#include "../../include/my.h"

int basic_flag(const char *str, va_list ap, int a)
{
    a = clean(str, a);
    flag(str, ap, a);
    flag_bis(str, ap, a);
    switch (str[a]) {
        case '#':
            a = hashtag(str, ap, a);
            if (str[a] != 'x' && str[a] != 'X' && str[a] != 'o')
                basic_flag(str, ap, a++);
            break;
        case '*':
            width_trick(str, ap, a);
            va_arg(ap, int);
            basic_flag(str, ap, a);
            a++;
            break;
    }
    return a;
}

int my_printf(const char *str, ...)
{
    va_list ap;
    int a = 0;

    va_start(ap, str);
    while (str[a] != '\0') {
        if (str[a] == '%') {
            a = basic_flag(str, ap, a);
            a++;
        }
        if (str[a] == '\n'
        || ((str[a] >= 32 && str[a] < 127) && str[a] != '%')) {
            my_putchar(str[a]);
            a++;
        }
    }
    va_end(ap);
    return 0;
}
