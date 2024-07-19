/*
** EPITECH PROJECT, 2022
** ft_flag.c
** File description:
** rpg
*/

#include "my.h"

void init_flag(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 320, 160);
    sfTexture *fr = sfTexture_createFromFile("assets/fr.png", NULL);
    sfTexture *eng = sfTexture_createFromFile("assets/eng.png", NULL);

    g->flag.fr = set_sprite(fr, set_pos(1668, 952), set_pos(0.30, 0.30));
    sfSprite_setTextureRect(g->flag.fr.sprite, rect);
    g->flag.eng = set_sprite(eng, set_pos(1794, 952), set_pos(0.30, 0.30));
    sfSprite_setTextureRect(g->flag.eng.sprite, rect);
}

void draw_flag(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 320, 160);
    sfIntRect rect2 = pos_rect(161, 0, 320, 160);

    if (g->option.langage == 0) {
        sfSprite_setTextureRect(g->flag.fr.sprite, rect);
        sfSprite_setTextureRect(g->flag.eng.sprite, rect2);
    } else {
        sfSprite_setTextureRect(g->flag.fr.sprite, rect2);
        sfSprite_setTextureRect(g->flag.eng.sprite, rect);
    }
    sfRenderWindow_drawSprite(g->window, g->flag.fr.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->flag.eng.sprite, NULL);
}

void click_flag(game_t *g)
{
    if (verrif_button_click(g, g->flag.fr.sprite)) {
        g->option.langage = 0;
        sfSprite_setScale(g->flag.fr.sprite, set_pos(0.30, 0.30));
        change_language(g);
    }
    if (verrif_button_click(g, g->flag.eng.sprite)) {
        g->option.langage = 1;
        sfSprite_setScale(g->flag.eng.sprite, set_pos(0.30, 0.30));
        change_language(g);
    }
}

void verrif_flag(game_t *g, sfSprite *sprite, sfVector2f pos)
{
    if (verrif_button_click(g, sprite) == 1) {
        sfSprite_setScale(sprite, set_pos(0.40, 0.40));
        sfSprite_setPosition(sprite, set_pos(pos.x - 16, pos.y - 8));
    } else {
        sfSprite_setScale(sprite, set_pos(0.30, 0.30));
        sfSprite_setPosition(sprite, pos);
    }
}

void in_flag(game_t *g)
{
    verrif_flag(g, g->flag.fr.sprite, set_pos(1668, 952));
    verrif_flag(g, g->flag.eng.sprite, set_pos(1794, 952));
}
