/*
** EPITECH PROJECT, 2022
** init_power_up.c
** File description:
** Init power up.
*/

#include "my.h"

my_sprite_t *create_small_yes(sfVector2f pos)
{
    my_sprite_t *list = malloc(sizeof(my_sprite_t) * 4);
    list[3].sprite = NULL;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    list[0] = set_sprite_rect(bg, pos, set_pos(1, 1),
    pos_rect(309, 472, 18, 14));
    sfSprite_setColor(list[0].sprite, sfYellow);
    list[1] = set_sprite_rect(bg, set_pos(pos.x + 25, pos.y),
    set_pos(1, 1), pos_rect(309, 472, 18, 14));
    sfSprite_setColor(list[1].sprite, sfYellow);
    list[2] = set_sprite_rect(bg, set_pos(pos.x + 50, pos.y),
    set_pos(1, 1), pos_rect(309, 472, 18, 14));
    sfSprite_setColor(list[2].sprite, sfYellow);
    return list;
}

void create_power_up_list2(create_select_power_up *list, int i,
sfIntRect *rect, sfVector2f p)
{
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *cara = sfTexture_createFromFile("assets/img/items.png", NULL);
    list[i].bg = set_sprite_rect(bg, set_pos(630 + p.x,
    300 + p.y), set_pos(3, 3), pos_rect(195, 270, 50, 50));
    if (list[i].have_nb >= 3) {
        list[i].have_nb = 3;
        sfSprite_setColor(list[i].bg.sprite,
        sfColor_fromRGBA(255, 255, 140, 255));
    }
    list[i].icon = set_sprite_rect(cara, set_pos(690 + p.x, 360 + p.y),
    set_pos(2.5, 2.5), rect[i]);
    list[i].fond = set_sprite_rect(bg, set_pos(677 + p.x, 345 + p.y),
    set_pos(2.5, 2.5), pos_rect(275, 377, 24, 24));
    list[i].square = create_small_square(set_pos(670 + p.x, 405 + p.y));
    list[i].oui = create_small_yes(set_pos(673 + p.x, 410 + p.y));
}

create_select_power_up *create_power_up_list(game_t *g)
{
    create_select_power_up *list = malloc(sizeof(create_select_power_up) * 12);
    list[11].bg.sprite = NULL;
    sfIntRect *rect = select_rect_icon();
    int y = 150;
    int e = 0;
    int x = 0;
    for (int i = 0; i < 11; i++) {
        list[i].have_nb = write_nb_in_save(g, i + 1);
        create_power_up_list2(list, i, rect, set_pos(e * y, x * 150));
        list[i].name = init_text("assets/fonts/ANY.ttf", 18,
        set_pos(652 + e * y, 315 + x * 150), langage[g->option.langage][0][i]);
        if ((i + 1) % 4 == 0) {
            e = 0;
            x++;
        } else
            e++;
    }
    return list;
}
