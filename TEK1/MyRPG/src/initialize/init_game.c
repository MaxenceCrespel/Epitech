/*
** EPITECH PROJECT, 2022
** init game
** File description:
** rpg
*/

#include "my.h"

void init_game_two(game_t *g)
{
    g->select = create_select_perso(g);
    g->stat_attack = create_attack_stat();
    g->chose_attack = create_chose_attack(g);
    g->scene = -1;
    g->old_scene = 0;
    g->pause = 0;
    init_sfx(g);
    init_lose(g);
    init_overlay_gem(g);
    g->writer.status = 0;
    g->writer.clock = sfClock_create();
    g->writer.x = 0;
    sfSound_play(g->sound.sound[INTRO]);
}

void click_help(game_t *g)
{
    return;
}

void init_helper(game_t *g)
{
    sfTexture *help = sfTexture_createFromFile("assets/help.png", NULL);
    g->help.help = set_sprite(help, set_pos(0, 0), set_pos(1, 1));
}

void init_game(game_t *g)
{
    g->option.langage = 0;
    create_window(g);
    get_save(g);
    srand(time(NULL));
    g->stat_p = create_stat_perso(g);
    g->stat_m = create_monster(g);
    init_start_intro(g);
    create_menu(g);
    init_flag(g);
    init_helper(g);
    create_select_bg(g);
    create_scene_up(g);
    create_option(g);
    init_cursor(g);
    g->achiev = create_achiev(g);
    create_power_up(g);
    init_game_two(g);
    g->reaper.speak = create_talk_reaper(g);
}
