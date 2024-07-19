/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int n = 0;

    for (; str[n] != '\0'; n++);
    return n;
}
