/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest , char const *src , int n)
{
    int a = 0;

    while (a < n) {
        dest[a] = src[a];
        a++;
    }
    if (my_strlen(src) == my_strlen(dest))
        dest[a] = '\0';
    return (dest);
}
