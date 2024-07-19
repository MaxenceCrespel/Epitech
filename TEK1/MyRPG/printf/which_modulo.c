/*
** EPITECH PROJECT, 2021
** modulo
** File description:
** print
*/

#include "include/my_printf.h"

void which_modulo2(char *str, va_list arg, int i)
{
    switch (str[i]) {
        case 'c' : my_putchar(va_arg(arg, int));
            break;
        case 's' : my_putstr(va_arg(arg, char *));
            break;
        case 'p' : my_putstr("Ox");
            convert_hex_x(va_arg(arg, int));
            break;
        case 'o' : my_put_nbr(convert_octal(va_arg(arg, int)));
            break;
        case '%' : my_putchar('%');
            break;
        default:
            my_putchar(str[i - 1]);
            my_putchar(str[i]);
            break;
    }
}

void which_modulo(char *str, va_list arg, int i)
{
    switch (str[i]) {
        case 'd' : my_put_nbr(va_arg(arg, int));
            break;
        case 'i' : my_put_nbr(va_arg(arg, int));
            break;
        case 'u' : my_put_unsigned(va_arg(arg, int));
            break;
        case 'x' : convert_hex_x(va_arg(arg, int));
            break;
        case 'X' : convert_hex_maj(va_arg(arg, int));
            break;
        case 'b' : convert_bin(va_arg(arg, int));
            break;
        default:
            which_modulo2(str, arg, i);
            break;
    }
}
