/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** width_trick
*/

#include <stdarg.h>
#include "../../include/my.h"

int check_space(va_list second, const char *str, int a, int espace)
{
    switch (str[a + 1]) {
        case 's':
            espace = va_arg(second, int) - my_strlen(va_arg(second, char *));
            break;
        case 'd':
            espace = va_arg(second, int) - nbr_size(second);
            break;
        case 'i':
            espace = va_arg(second, int) - nbr_size(second);
            break;
        case 'c':
            espace = va_arg(second, int) - 1;
            break;
        case '%':
            espace = 0;
            break;
    }
    return espace;
}

void width_trick(const char *str, va_list ap, int a)
{
    int espace = 0;
    va_list second;

    va_copy(second, ap);
    espace = check_space(second, str, a, espace);
    for (; str[a - 1] != '%' && str[a - 1] != ' '; a--)
        if (str[a - 1] == ' ')
            espace--;
    while (espace > 0) {
        my_putchar(' ');
        espace--;
    }
    va_end(second);
}
