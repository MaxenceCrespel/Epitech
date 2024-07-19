/*
** EPITECH PROJECT, 2022
** init_stat_chara.c
** File description:
** Init stat character
*/

#include "my.h"

sfIntRect *select_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect) * 6);
    rect[0] = pos_rect(550, 30, 30, 35);
    rect[1] = pos_rect(201, 28, 23, 35);
    rect[2] = pos_rect(236, 0, 27, 35);
    rect[3] = pos_rect(550, 30, 30, 35);
    rect[4] = pos_rect(201, 28, 23, 35);
    rect[5] = pos_rect(236, 0, 27, 35);
    return rect;
}

void create_select_boucle(select_t *select, int i, sfIntRect *rect, game_t *g)
{
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *cara = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    static int y = 240;
    static int e = 0;
    static int x = 0;
    select[i].bg = set_sprite_rect(bg, set_pos(570 + (e * y),
    300 + (x * 240)), set_pos(4, 4), pos_rect(195, 270, 50, 50));
    select[i].perso = set_sprite(cara, set_pos(605 + (e * y),
    360 + (x * 240)), set_pos(3.2, 3.2));
    sfSprite_setTextureRect(select[i].perso.sprite, rect[i]);
    select[i].name = init_text("assets/fonts/ANY.ttf", 20,
    set_pos(605 + (e * y), 330 + (x * 240)), langage[g->option.langage][1][i]);
    if ((i + 1) % 3 == 0) {
        e = 0;
        x++;
    } else
        e++;
}

select_t *create_select_perso(game_t *g)
{
    select_t *select = NULL;
    select = malloc(sizeof(select_t) * 7);
    select[6].bg.sprite = NULL;
    sfIntRect *rect = select_rect();
    for (int i = 0; i < 6; i++)
        create_select_boucle(select, i, rect, g);
    return select;
}

void stat_cara_un2(stat_cara_t *stat)
{
    stat->armor = 5;
    stat->cooldown = 10;
    stat->pene = 3;
    stat->recov = 1;
    stat->growth = 0;
    stat->duration = 15;
    stat->rect = malloc(sizeof(sfIntRect) * 4);
    stat->rect[0] = pos_rect(553, 30, 30, 35);
    stat->rect[1] = pos_rect(553, 62, 30, 35);
    stat->rect[2] = pos_rect(373, 3, 30, 35);
    stat->rect[3] = pos_rect(444, 3, 30, 34);
}

stat_cara_t stat_cara_un(void)
{
    stat_cara_t stat;
    sfTexture *text = sfTexture_createFromFile("assets/img/characters.png",
    NULL);
    stat.sprite = set_sprite(text, set_pos(900, 500), set_pos(3, 3));
    stat.area = 25;
    stat.life = 120;
    stat.speed = 8;
    stat.magnet = 35;
    stat.max_life = 120;
    stat.rect = 0;
    stat.ms = 10;
    stat.dir = 0;
    stat_cara_un2(&stat);
    return stat;
}
