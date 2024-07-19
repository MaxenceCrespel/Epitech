/*
** EPITECH PROJECT, 2022
** init_menu.c
** File description:
** Init the sprite menu.
*/

#include "my.h"

void create_window(game_t *g)
{
    const sfUint8 *ic;
    sfVideoMode vm = {1920, 1080, 32};

    g->window = sfRenderWindow_create(vm, "Vampire Survivor", sfClose
    | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(g->window, 60);
    ic = sfImage_getPixelsPtr(sfImage_createFromFile("assets/logo.png"));
    sfRenderWindow_setIcon(g->window, 512, 512, ic);
}

void create_menu3(game_t *g)
{
    char *str = "assets/fonts/ANY.ttf";
    sfIntRect rect2 = pos_rect(0, 0, 48, 33);
    sfTexture *but1 = sfTexture_createFromFile("assets/buttons1.png", NULL);
    g->menu.help = set_sprite(but1, set_pos(497, 776), set_pos(5.8, 1.9));
    sfSprite_setTextureRect(g->menu.help.sprite, rect2);
    g->menu.t_help = init_text(str, 30, set_pos(535, 785), "HOW TO PLAY");
    g->menu.but2 = create_button(set_pos(0, 0), set_pos(1920, 100));
    sfTexture *text = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->menu.img_coin = set_sprite(text, set_pos(773, 12), set_pos(2.8, 2.8));
    sfIntRect img_coin = pos_rect(250, 480, 30, 30);
    sfSprite_setTextureRect(g->menu.img_coin.sprite, img_coin);
    g->menu.coin = set_sprite(text, set_pos(740, 10), set_pos(8, 1.7));
    sfIntRect coin = pos_rect(268, 0, 50, 50);
    sfSprite_setTextureRect(g->menu.coin.sprite, coin);
    g->img_k_m = set_sprite_rect(text, set_pos(1425, 80),
    set_pos(3, 3), pos_rect(304, 461, 9, 8));
    g->arrow = set_sprite_rect(text, set_pos(1850, 540),
    set_pos(3, 3), pos_rect(285, 329, 14, 13));
}

void create_menu2(game_t *g, sfIntRect rect, sfTexture *bg)
{
    char *str = "assets/fonts/ANY.ttf";
    sfIntRect rect2 = pos_rect(0, 0, 48, 33);
    sfTexture *but1 = sfTexture_createFromFile("assets/buttons1.png", NULL);
    sfTexture *but2 = sfTexture_createFromFile("assets/buttons2.png", NULL);
    g->menu.t_start = init_text(str, 50, set_pos(903, 600), "START");
    g->menu.option = set_sprite(but1, set_pos(1180, 15), set_pos(5.4, 2.1));
    sfSprite_setTextureRect(g->menu.option.sprite, rect2);
    g->menu.t_option = init_text(str, 40, set_pos(1213, 20), "SETTINGS");
    g->menu.quit = set_sprite_rect(but2, set_pos(528, 15),
    set_pos(3.8, 2.1), rect2);
    g->menu.t_quit = init_text(str, 40, set_pos(570, 20), "QUIT");
    g->menu.power = set_sprite(but1, set_pos(835, 770), set_pos(6, 2.3));
    sfSprite_setTextureRect(g->menu.power.sprite, rect2);
    g->menu.t_power = init_text(str, 40, set_pos(883, 777), "POWER UP");
    g->menu.achiev = set_sprite(but1, set_pos(1180, 776), set_pos(5.8, 1.9));
    sfSprite_setTextureRect(g->menu.achiev.sprite, rect2);
    g->menu.t_achiev = init_text(str, 30, set_pos(1212, 785), "ACHIEVEMENTS");
    create_menu3(g);
}

void create_menu(game_t *g)
{
    sfIntRect rect = pos_rect(318, 0, 50, 33);
    sfTexture *bg = sfTexture_createFromFile("assets/img/introBG.png", NULL);
    sfIntRect rect2 = pos_rect(0, 0, 48, 33);
    sfTexture *but1 = sfTexture_createFromFile("assets/buttons1.png", NULL);
    g->menu.bg = set_sprite(bg, set_pos(-20, -100), set_pos(5, 5));
    bg = sfTexture_createFromFile("assets/img/illustrations.png", NULL);
    g->menu.vamp = set_sprite_rect(bg, set_pos(0, 200), set_pos(4, 4),
    pos_rect(193, 0, 180, 230));
    sfSprite_setColor(g->menu.vamp.sprite,
    sfColor_fromRGBA(255, 255, 255, 170));
    g->menu.pers = set_sprite_rect(bg, set_pos(433, 430), set_pos(3.35, 3.35),
    pos_rect(0, 0, 360, 193));
    g->menu.pers2 = set_sprite_rect(bg, set_pos(1200, 200), set_pos(3.5, 3.5),
    pos_rect(210, 190, 220, 180));
    bg = sfTexture_createFromFile("assets/img/title.png", NULL);
    g->menu.logo = set_sprite(bg, set_pos(740, 250), set_pos(1.4, 1.4));
    bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->menu.start = set_sprite(but1, set_pos(835, 600), set_pos(6, 2.3));
    sfSprite_setTextureRect(g->menu.start.sprite, rect2);
    create_menu2(g, rect, bg);
}
