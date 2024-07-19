/*
** EPITECH PROJECT, 2022
** init_icon.c
** File description:
** Init icon.
*/

#include "my.h"

chose_attack_t *create_chose_attack(game_t *g)
{
    chose_attack_t *attack = malloc(sizeof(chose_attack_t) * 7);
    attack[6].bg.sprite = NULL;
    attack[0] = create_chose_fouet(g);
    attack[1] = create_chose_fire(g);
    attack[2] = create_chose_couteau(g);
    attack[3] = create_chose_lorel(g);
    attack[4] = create_chose_ms(g);
    attack[5] = create_chose_cooldown(g);
    return attack;
}

image_option_t *create_option_img(game_t *g)
{
    char *str = "assets/fonts/ANY.ttf";
    image_option_t *option = malloc(sizeof(image_option_t) * 5);
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    option[4].img_opt.sprite = NULL;
    for (int i = 0; i < 4; i++) {
        option[i].img_opt = set_sprite_rect(bg, set_pos(1010, 290 + (i * 125)),
        set_pos(3, 3), pos_rect(283, 348, 24, 24));
        option[i].non = set_sprite_rect(bg, set_pos(1020, 300 + (i * 125)),
        set_pos(3, 3), pos_rect(322, 440, 17, 17));
        option[i].oui = set_sprite_rect(bg, set_pos(1019, 308 + (i * 125)),
        set_pos(3, 3), pos_rect(309, 472, 18, 14));
        option[i].status = 0;
    }
    option[0].text = init_text(str, 40, set_pos(650, 300), "Sounds");
    option[1].text = init_text(str, 40, set_pos(650, 425), "Music");
    option[2].text = init_text(str, 40, set_pos(650, 550), "Fps");
    option[3].text = init_text(str, 40, set_pos(650, 675), "Damage Numbers");
    return option;
}

void create_option(game_t *g)
{
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfIntRect rect = pos_rect(0, 0, 48, 33);
    sfTexture *but2 = sfTexture_createFromFile("assets/buttons2.png", NULL);
    g->option.bg = set_sprite_rect(bg, set_pos(550, 150),
    set_pos(16, 17), pos_rect(228, 175, 48, 48));
    g->option.img = create_option_img(g);
    g->option.back = set_sprite_rect(but2, set_pos(1170, 15),
    set_pos(3.8, 2.1), rect);
    g->option.quit = set_sprite_rect(but2, set_pos(528, 15),
    set_pos(3.8, 2.1), rect);
    g->option.t_back = init_text("assets/fonts/ANY.ttf",
    40, set_pos(1212, 20), "BACK");
    g->option.t_quit = init_text("assets/fonts/ANY.ttf",
    40, set_pos(570, 20), "QUIT");
}

sfIntRect *select_rect_icon(void)
{
    sfIntRect *list = malloc(sizeof(sfIntRect) * 11);
    list[0] = pos_rect(449, 40, 16, 14);
    list[1] = pos_rect(616, 35, 15, 13);
    list[2] = pos_rect(383, 41, 14, 14);
    list[3] = pos_rect(112, 35, 14, 13);
    list[4] = pos_rect(283, 18, 13, 15);
    list[5] = pos_rect(650, 1, 16, 16);
    list[6] = pos_rect(532, 2, 14, 14);
    list[7] = pos_rect(246, 49, 13, 13);
    list[8] = pos_rect(513, 49, 14, 13);
    list[9] = pos_rect(531, 34, 14, 14);
    list[10] = pos_rect(301, 17, 15, 16);
    return list;
}

my_sprite_t *create_small_square(sfVector2f pos)
{
    my_sprite_t *list = malloc(sizeof(my_sprite_t) * 4);
    list[3].sprite = NULL;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    list[0] = set_sprite_rect(bg, pos, set_pos(1, 1),
    pos_rect(283, 348, 24, 24));
    list[1] = set_sprite_rect(bg, set_pos(pos.x + 25, pos.y),
    set_pos(1, 1), pos_rect(283, 348, 24, 24));
    list[2] = set_sprite_rect(bg, set_pos(pos.x + 50, pos.y),
    set_pos(1, 1), pos_rect(283, 348, 24, 24));
    return list;
}
