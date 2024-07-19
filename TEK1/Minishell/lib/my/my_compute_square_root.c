/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int a = 1;

    if (nb == 1)
        return (1);
    if (nb <= 0)
        return (0);
    while (a < nb) {
        if ((a * a) == nb)
            return (a);
        a++;
    }
    return (0);
}
