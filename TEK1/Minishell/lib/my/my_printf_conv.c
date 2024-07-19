/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_printf_conv
*/

#include "../../include/my.h"

void octal(unsigned int nbr)
{
    unsigned int res = 0;
    int a = 1;

    while (nbr != 0) {
        res = res + (nbr % 8) * a;
        nbr = nbr / 8;
        a = a * 10;
    }
    my_put_unsigned_nbr(res);
}

void binary(unsigned int nbr)
{
    unsigned int res = 0;
    int a = 1;

    while (nbr != 0) {
        res = res + (nbr % 2) * a;
        nbr = nbr / 2;
        a = a * 10;
    }
    my_put_unsigned_nbr(res);
}

void hexadecimal(unsigned int nbr, char maj)
{
    char res = 0;
    int a = 16;

    while (nbr / a != 0) {
        a = a * 16;
    }
    while (a != 1) {
        res = nbr / (a / 16);
        if (res > 9 && maj == 'A') {
            res += 55;
            my_putchar(res);
        } else if (res > 9 && maj == 'a') {
            res += 87;
            my_putchar(res);
        } else
            my_put_unsigned_nbr(res);
        nbr = nbr % (a / 16);
        a /= 16;
    }
}
