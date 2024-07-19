/*
** EPITECH PROJECT, 2021
** convert
** File description:
** pritn
*/

#include "include/my_printf.h"

int convert_octal(int nb)
{
    int octal = 0;
    int i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb != 0) {
        octal = octal + (nb % 8) * i;
        nb = nb / 8;
        i = i * 10;
    }
    return (octal);
}

int convert_bin2(int nb)
{
    char const *bin = "10";
    int i = 1;
    int max = 1;

    if (nb < 0)
        nb = nb * (-1);
    while ((nb / max) >= 2)
        max *= 2;
    while (max > 0) {
        i = (nb / max) % 2;
        my_putchar(bin[i]);
        max = max / 2;
    }
}

int convert_bin(int nb)
{
    char const *bin = "01";
    int i = 1;
    int max = 1;

    if (nb < 0) {
        convert_bin2(nb);
        return 0;
    }
    while ((nb / max) >= 2)
        max *= 2;
    while (max > 0) {
        i = (nb / max) % 2;
        my_putchar(bin[i]);
        max = max / 2;
    }
}

int convert_hex_x(int nb)
{
    char const *hex = "0123456789abcdef";
    int i = 1;
    int max = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while ((nb / max) >= 16)
        max *= 16;
    while (max > 0) {
        i = (nb / max) % 16;
        my_putchar(hex[i]);
        max = max / 16;
    }
}

int convert_hex_maj(int nb)
{
    char const *hex = "0123456789ABCDEF";
    int i = 1;
    int max = 1;

    if (nb < 0) {
        nb = -nb;
    }
    while ((nb / max) >= 16)
        max *= 16;
    while (max > 0) {
        i = (nb / max) % 16;
        my_putchar(hex[i]);
        max = max / 16;
    }
}
