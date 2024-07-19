/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb , int p)
{
    int a = nb;

    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    else
        return (a * my_compute_power_rec(nb, p - 1));
}
