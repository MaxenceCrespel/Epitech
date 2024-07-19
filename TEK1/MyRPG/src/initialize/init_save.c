/*
** EPITECH PROJECT, 2022
** init_save.c
** File description:
** Init save & icon.
*/

#include "my.h"

void create_stat_icon_two(my_sprite_t *stat, sfTexture *bg, sfVector2f vec)
{
    stat[5] = set_sprite_rect(bg, set_pos(131, 560), vec,
    pos_rect(650, 1, 16, 16));
    stat[6] = set_sprite_rect(bg, set_pos(131, 585), vec,
    pos_rect(532, 2, 14, 14));
    stat[7] = set_sprite_rect(bg, set_pos(133, 610), vec,
    pos_rect(248, 51, 11, 11));
    stat[8] = set_sprite_rect(bg, set_pos(133, 660), vec,
    pos_rect(513, 50, 12, 13));
    stat[9] = set_sprite_rect(bg, set_pos(131, 685), vec,
    pos_rect(531, 34, 14, 14));
    stat[10] = set_sprite_rect(bg, set_pos(130, 710), vec,
    pos_rect(301, 17, 15, 16));
}

my_sprite_t *create_stat_icone(void)
{
    my_sprite_t *stat = malloc(sizeof(my_sprite_t) * 12);
    stat[11].sprite = NULL;
    sfVector2f vec = {1.5, 1.5};
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    stat[0] = set_sprite_rect(bg, set_pos(130, 410), vec,
    pos_rect(450, 40, 16, 14));
    stat[1] = set_sprite_rect(bg, set_pos(133, 435), vec,
    pos_rect(617, 36, 12, 11));
    stat[2] = set_sprite_rect(bg, set_pos(131, 458), vec,
    pos_rect(383, 41, 14, 14));
    stat[3] = set_sprite_rect(bg, set_pos(131, 485), vec,
    pos_rect(114, 35, 14, 10));
    stat[4] = set_sprite_rect(bg, set_pos(134, 533), vec,
    pos_rect(283, 18, 13, 15));
    create_stat_icon_two(stat, bg, vec);
    return stat;
}

void create_select_bg(game_t *g)
{
    char *ttf = "assets/fonts/ANY.ttf";
    char *str = "Character Selection";
    g->menu.select = -1;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->menu.over_bot = set_sprite_rect(bg, set_pos(580, 750),
    set_pos(13.5, 4), pos_rect(195, 270, 50, 50));
    g->menu.font = set_sprite(bg, set_pos(450, 100), set_pos(20, 20.5));
    sfIntRect r_font = pos_rect(228, 175, 48, 48);
    sfSprite_setTextureRect(g->menu.font.sprite, r_font);
    g->menu.text = init_text(ttf, 60, set_pos(590, 190), str);
    g->d_stat.bg = set_sprite(bg, set_pos(100, 350), set_pos(6, 10));
    sfSprite_setTextureRect(g->d_stat.bg.sprite, r_font);
    g->d_stat.stat_n = create_stat_name();
    g->d_stat.stat_i = create_stat_icone();
    g->menu.old_select = -1;
}

void init_save(game_t *g)
{
    g->save.i_or = 0;
    g->save.t_or = init_text("assets/fonts/KO.ttf", 40,
    set_pos(1050, 22), my_itoa(g->save.i_or));
    g->save.area = 0;
    g->save.magnet = 0;
    g->save.max_life = 0;
    g->save.ms = 0;
    g->save.speed = 0;
    g->save.armor = 0;
    g->save.cooldown = 0;
    g->save.pene = 0;
    g->save.recov = 0;
    g->save.duration = 0;
    g->save.growth = 0;
    g->save.perso = malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i++)
        g->save.perso[i] = 0;
    g->save.perso[0] = 1;
}
