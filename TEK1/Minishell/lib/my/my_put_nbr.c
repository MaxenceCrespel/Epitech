/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
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
        my_put_nbr(nb / 10);
    nb %= 10;
    my_putchar(nb + 48);
    return (0);
}
