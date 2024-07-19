/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_getnbr
*/

int check_size(char const *str, int a)
{
    if (str[a] > 2 && str[a + 1] > 1 && str[a + 2] > 4 && str[a + 3] > 7
        && str[a + 4] > 4 && str[a + 5] > 8 && str[a + 6] > 3 && str[a + 7] > 6
        && str[a + 8] > 4 && str[a + 9] > 7 || str[a - 1] == '-' && str[a] > 2
        && str[a + 1] > 1 && str[a + 2] > 4 && str[a + 3] > 7 && str[a + 4] > 4
        && str[a + 5] > 8 && str[a + 6] > 3 && str[a + 7] > 6 && str[a + 8] > 4
        && str[a + 9] > 7)
        return (84);
    else
        return 0;
}

int my_getnbr_bis(char const *str, int nbr, int b)
{
    if (str[b] == '-')
        nbr = nbr * (-1);
    return nbr;
}

int my_getnbr(char const *str)
{
    int a = 0;
    int nbr = 0;
    int b = 0;

    for (; str[a] < 48 || str[a] > 57; a++)
        if (check_size(str, a) == 84)
            return (0);
    b = a - 1;
    while (str[a] != '\0') {
        if (str[a] < 48 || str[a] > 57) {
            nbr = my_getnbr_bis(str, nbr, b);
            return (nbr);
        } else {
            nbr = nbr * 10 + (str[a] - 48);
            a++;
        }
    }
    if (str[b] == '-')
        nbr = nbr * (-1);
    return (nbr);
}
