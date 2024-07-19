/*
** EPITECH PROJECT, 2021
** put_unsigned
** File description:
** printfp
*/

#include "include/my_printf.h"

int my_put_unsigned(unsigned int nb)
{
    unsigned int i;
    if (nb > 9)
        my_put_nbr(nb / 10);
    i = nb % 10 + 48;
    my_putchar(i);
    return 0;
}
