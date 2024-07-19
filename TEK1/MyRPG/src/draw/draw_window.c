/*
** EPITECH PROJECT, 2022
** draw_window.c
** File description:
** Draw window
*/

#include "my.h"

int init_cursor(game_t *g)
{
    const char *path = "assets/sword.png";

    sfTexture *sword = sfTexture_createFromFile(path, NULL);
    g->cursor = set_sprite(sword, set_pos(550, 550), set_pos(0.35, 0.35));
}

void refresh_cursor(game_t *g)
{
    sfVector2f pos = {g->mouse.x - 15, g->mouse.y - 1};
    sfSprite_setPosition(g->cursor.sprite, pos);
    sfRenderWindow_setMouseCursorVisible(g->window, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->cursor.sprite, NULL);
}

int init_lose(game_t *g)
{
    const char *path = "assets/img/gameover.png";
    char *font = "assets/fonts/ANY.ttf";
    char *but1 = "assets/buttons1.png";
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    sfTexture *lose = sfTexture_createFromFile(path, NULL);
    sfTexture *but = sfTexture_createFromFile(but1, NULL);
    g->lose.over = set_sprite(lose, set_pos(794, 270), set_pos(1, 1));
    g->lose.quit.sprite = sfSprite_copy(g->option.quit.sprite);
    sfSprite_setPosition(g->lose.quit.sprite, set_pos(730, 550));
    g->lose.menu.sprite = sfSprite_copy(g->option.quit.sprite);
    sfSprite_setTexture(g->lose.menu.sprite, but, sfTrue);
    sfSprite_setPosition(g->lose.menu.sprite, set_pos(1005, 550));
    sfSprite_setTextureRect(g->lose.menu.sprite, rect);
    g->lose.t_quit = init_text(font, 40, set_pos(770, 555), "QUIT");
    g->lose.t_menu = init_text(font, 40, set_pos(1049, 555), "MENU");
    return (0);
}

int display_lose(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->lose.over.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->lose.menu.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->lose.quit.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->lose.t_menu.text, NULL);
    sfRenderWindow_drawText(g->window, g->lose.t_quit.text, NULL);
    return (0);
}

void draw_window(game_t *g)
{
    if (g->scene == -1)
        draw_start_intro(g);
    if (g->scene == 0 || g->scene == 2 || g->scene == 5
    || g->scene == 6 || g->scene == 7 || g->scene == 10) {
        sfRenderWindow_clear(g->window, sfBlack);
        draw_menu(g);
    }
    if (g->scene == 1 || g->scene == 3 || g->scene == 4
    || (g->scene == 5 && g->old_scene == 1)) {
        sfRenderWindow_clear(g->window, sfBlack);
        display_game(g);
    }
    if (g->scene == 9) {
        sfRenderWindow_clear(g->window, sfBlack);
        display_game(g);
        display_lose(g);
    }
    refresh_cursor(g);
    sfRenderWindow_display(g->window);
}
