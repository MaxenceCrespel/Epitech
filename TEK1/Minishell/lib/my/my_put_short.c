/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_put_short
*/

#include "../../include/my.h"

int my_put_short(short int nb)
{
    if (nb == 0) {
        my_putchar(nb + 48);
        return (0);
    }
    if (nb < 0) {
        nb *= (-1);
        my_putchar('-');
    }
    if (nb > 9)
        my_put_short(nb / 10);
    nb %= 10;
    my_putchar(nb + 48);
    return (0);
}
