/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_put_unsigned_nbr
*/

#include "../../include/my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb == 0) {
        my_putchar(nb + 48);
        return (0);
    }
    if (nb > 9)
        my_put_unsigned_nbr(nb / 10);
    nb %= 10;
    my_putchar(nb + 48);
    return (0);
}
