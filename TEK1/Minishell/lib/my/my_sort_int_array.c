/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_sort_int_array
*/

int my_put_nbr(int nb);

void my_putchar(char c);

int my_sort_int_array_bis(int *array, int sort, int a)
{
    int stock;

    if (array[a] > array[a + 1]) {
        sort = 0;
        stock = array[a];
        array[a] = array[a + 1];
        array[a + 1] = stock;
    }
}

void my_sort_int_array(int *array , int size)
{
    int a = 0;
    int sort = 0;

    my_put_nbr(array[a]);
    my_putchar('\n');
    while (sort != 1) {
        a = 0;
        while (a < size) {
            sort = 1;
            sort = my_sort_int_array_bis(array, sort, a);
            a++;
        }
    }
}
