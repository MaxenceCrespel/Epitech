/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** int to str
*/

#include "../../include/my.h"

void int_to_str_end(char str[], int negatif, int size)
{
    if (negatif == 1) {
        move_right(str);
        str[0] = '-';
        str[size + 1] = '\0';
    } else
        str[size] = '\0';
}

void int_to_str(char str[], int nb)
{
    int i = 0;
    int size = 0;
    int negatif = 0;

    if (nb < 0) {
        negatif = 1;
        nb *= -1;
    }
    for (int n = nb; n != 0; size++)
        n = n / 10;
    for (int q = 0; i < size; i++) {
        q = nb % 10;
        nb = nb / 10;
        str[size - (i + 1)] = q + 48;
    }
    int_to_str_end(str, negatif, size);
}
