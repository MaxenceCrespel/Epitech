/*
** EPITECH PROJECT, 2022
** init_monster.c
** File description:
** Init monster.
*/

#include "my.h"

void get_save_achiev(game_t *g, achive_t *list)
{
    struct stat stats;
    int fd = open(".achiev", O_RDONLY);
    char *buffer;

    if (fd == -1 || (stat(".achiev", &stats) == -1))
        return init_save_achiev(list);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    buffer[stats.st_size] = '\0';
    if (read(fd, buffer, stats.st_size) == -1) {
        free(buffer);
        return init_save_achiev(list);
    }
    close(fd);
    verif_file_achiev(buffer, g, list);
    free(buffer);
}

void check_complete(achive_t *list)
{
    for (int i = 0; i < 10; i++)
        if (list[i].actu >= list[i].max)
            list[i].complete = 1;
}

achive_t *create_achiev(game_t *g)
{
    achive_t *list = malloc(sizeof(achive_t) * 11);
    list[10].img_opt.sprite = NULL;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    get_save_achiev(g, list);
    for (int i = 0; i < 10; i++) {
        list[i].img_opt = set_sprite_rect(bg, set_pos(1110, 275 + (i * 65)),
        set_pos(2, 2), pos_rect(283, 348, 24, 24));
        list[i].non = set_sprite_rect(bg, set_pos(1117, 282 + (i * 65)),
        set_pos(2, 2), pos_rect(322, 440, 17, 17));
        list[i].oui = set_sprite_rect(bg, set_pos(1116, 287 + (i * 65)),
        set_pos(2, 2), pos_rect(309, 472, 18, 14));
        list[i].max = ACHIEV_MAX[i];
        list[i].text = init_text("assets/fonts/ANY.ttf", 25,
        set_pos(650, 280 + (i * 65)), langage[g->option.langage][4][i]);
        list[i].complete = 0;
        list[i].t_actu = init_text("assets/fonts/ANY.ttf", 25,
        set_pos(1180, 280 + (i * 65)), my_itoa(list[i].actu));
    }
    check_complete(list);
    return list;
}

void create_power_up(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);
    sfTexture *but3 = sfTexture_createFromFile("assets/buttons3.png", NULL);
    g->power_up.list = create_power_up_list(g);
    g->power_up.display = -1;
    g->power_up.description = init_text("assets/fonts/ANY.ttf",
    18, set_pos(800, 800), "0");
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->power_up.buy = set_sprite_rect(but3, set_pos(1060, 835),
    set_pos(2, 2), rect);
    g->power_up.t_buy = init_text("assets/fonts/ANY.ttf", 22,
    set_pos(1087, 850), "Buy");
    g->power_up.coins = set_sprite_rect(bg, set_pos(1090, 803),
    set_pos(2, 2), pos_rect(323, 459, 10, 10));
    g->power_up.price = init_text("assets/fonts/ANY.ttf", 22,
    set_pos(1110, 800), "0");
}

monster_t create_monster_un(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(3, 3));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(10, 0));
    list.life = 33;
    list.speed = 4.1;
    list.damage = 7;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(1114, 1568, 23, 22);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(1138, 1732, 19, 22);
    list.rect[2] = pos_rect(1170, 1777, 17, 22);
    list.rect[3] = pos_rect(1138, 1732, 19, 22);
    return list;
}
