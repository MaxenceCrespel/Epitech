/*
** EPITECH PROJECT, 2022
** intro game two
** File description:
** reaper
*/

#include "my.h"

text_t *create_talk_reaper(game_t *g)
{
    char *ttf = "assets/fonts/ANY.ttf";
    text_t *list = malloc(sizeof(text_t) * 12);
    for (int i = 0; i != 12; i++) {
        list[i] = init_text(ttf, 30, set_pos(300, 800),
        langage[g->option.langage][5][i]);
    }
    return list;
}

void create_reaper(game_t *g)
{
    sfTexture *bg;
    bg = sfTexture_createFromFile("assets/img/characters.png", NULL);
    g->reaper.reaper = set_sprite_rect(bg, set_pos(750, 490),
    set_pos(3, 3), pos_rect(665, 72, 41, 47));
    g->reaper.speak = create_talk_reaper(g);
    g->reaper.stop = 0;
    g->reaper.next = 0;
    g->reaper.clock = sfClock_create();
    g->reaper.rect1 = create_button(set_pos(290, 900), set_pos(280, 50));
    sfRectangleShape_setOutlineThickness(g->reaper.rect1, 3);
    sfRectangleShape_setOutlineColor(g->reaper.rect1, sfBlue);
    g->reaper.rect2 = create_button(set_pos(290, 970), set_pos(350, 50));
    sfRectangleShape_setOutlineThickness(g->reaper.rect2, 3);
    sfRectangleShape_setOutlineColor(g->reaper.rect2, sfBlue);
}

void event_intro2_bis(game_t *g, sfEvent event)
{
    if ((event.key.code == sfKeyA || event.key.code == sfKeySpace)
    && g->start.nb_item != 0) {
        g->reaper.stop = 1;
    }
    if ((event.key.code == sfKeyA || event.key.code == sfKeySpace)
    && g->start.nb_item == 6) {
        sfMusic_stop(g->music.music[1]);
        sfMusic_play(g->music.music[2]);
    }
}

void event_intro2(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeyEscape && g->start.nb_item == 0) {
        sfMusic_stop(g->music.music[2]);
        sfMusic_play(g->music.music[1]);
        g->reaper.stop = 1;
    }
    if (event.key.code == sfKeyEscape && g->start.nb_item != 0) {
        sfMusic_stop(g->music.music[1]);
        sfMusic_play(g->music.music[2]);
        g->reaper.stop = 1;
    }
    if (event.key.code == sfKeyA || event.key.code == sfKeySpace) {
        g->reaper.next++;
        g->writer.x = 0;
        g->writer.status = 0;
    }
    event_intro2_bis(g, event);
}

void event_intro3(game_t *g, sfEvent event)
{
    if (g->reaper.next == 3) {
        sfMusic_play(g->music.music[1]);
        g->reaper.next = 4;
        g->reaper.stop = 1;
    }
    if (event.type == sfEvtMouseButtonPressed && (g->start.end == 4
    || g->start.nb_item == 8)) {
        if (verrif_button_rect(g, g->reaper.rect1)) {
            g->reaper.stop = 1;
            g->start.end = 0;
            g->start.nb_item = 8;
        }
        if (verrif_button_rect(g, g->reaper.rect2)) {
            quit_game(g);
            g->reaper.stop = 1;
        }
    }
}
