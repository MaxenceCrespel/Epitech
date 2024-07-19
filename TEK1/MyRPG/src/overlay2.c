/*
** EPITECH PROJECT, 2022
** overlay2
** File description:
** add fucntion
*/

#include "my.h"

int *random_x(game_t *g, int max, int min, int num)
{
    int i = 0;
    int n = 0;
    num = num + 1;
    int *tmp = malloc(sizeof(int) * num);

    while (i < num) {
        n = rand() % max + min;
        tmp[i] = n;
        i++;
    }
    return (tmp);
}

int *random_y(game_t *g, int max, int min, int num)
{
    int i = 0;
    int n = 0;
    num = num + 1;
    int *tmp = malloc(sizeof(int) * num);

    while (i < num) {
        if (i == 100 || i == 200 || i == 300) {
            max += 125;
            min += 125;
        }
        n = rand() % max + min;
        tmp[i] = n;
        i++;
    }
    return (tmp);
}

sfTexture **init_texture_gem2(sfTexture **texture)
{
    const char *path6 = "assets/gem/gem_6.png";
    const char *path7 = "assets/gem/gem_7.png";
    const char *path8 = "assets/gem/gem_8.png";
    const char *path9 = "assets/gem/gem_9.png";
    const char *path10 = "assets/gem/gem_10.png";

    texture[5] = sfTexture_createFromFile(path6, NULL);
    texture[6] = sfTexture_createFromFile(path7, NULL);
    texture[7] = sfTexture_createFromFile(path8, NULL);
    texture[8] = sfTexture_createFromFile(path9, NULL);
    texture[9] = sfTexture_createFromFile(path10, NULL);
    return (texture);
}

sfTexture **init_texture_gem(game_t *g)
{
    const char *path1 = "assets/gem/gem_1.png";
    const char *path2 = "assets/gem/gem_2.png";
    const char *path3 = "assets/gem/gem_3.png";
    const char *path4 = "assets/gem/gem_4.png";
    const char *path5 = "assets/gem/gem_5.png";
    sfTexture **texture = malloc(sizeof(sfTexture *) * 10);

    texture[0] = sfTexture_createFromFile(path1, NULL);
    texture[1] = sfTexture_createFromFile(path2, NULL);
    texture[2] = sfTexture_createFromFile(path3, NULL);
    texture[3] = sfTexture_createFromFile(path4, NULL);
    texture[4] = sfTexture_createFromFile(path5, NULL);
    texture = init_texture_gem2(texture);
    return (texture);
}

float *my_tab_of_float(float nb, int length)
{
    int x = 0;
    length = length + 1;
    float *res = malloc(sizeof(float) * length);

    while (x < length) {
        res[x] = nb;
        x++;
    }
    return (res);
}
