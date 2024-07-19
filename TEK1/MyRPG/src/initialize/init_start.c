/*
** EPITECH PROJECT, 2022
** init satrt
** File description:
** prg
*/

#include "my.h"

bar_health create_bar_hp(void)
{
    bar_health temp;
    sfTexture *texture;
    texture = sfTexture_createFromFile("assets/Healthbar.png", NULL);
    temp.bg = sfSprite_create();
    sfSprite_setTexture(temp.bg, texture, sfTrue);
    texture = sfTexture_createFromFile("assets/HealthbarFront.png", NULL);
    temp.front = sfSprite_create();
    sfSprite_setTexture(temp.front, texture, sfTrue);
    temp.bar = sfRectangleShape_create();
    sfRectangleShape_setScale(temp.bar, set_pos(1.5, 1.5));
    sfSprite_setScale(temp.bg, set_pos(1.5, 1.5));
    sfSprite_setScale(temp.front, set_pos(1.5, 1.5));
    sfRectangleShape_setSize(temp.bar, set_pos(67, 6));
    sfRectangleShape_setFillColor(temp.bar, sfGreen);
    sfSprite_setPosition(temp.bg, set_pos(890, 600));
    sfRectangleShape_setPosition(temp.bar, set_pos(892, 602));
    sfSprite_setPosition(temp.front, set_pos(890, 600));
    return (temp);
}

void init_start_two_bis(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);
    sfTexture *but1 = sfTexture_createFromFile("assets/buttons1.png", NULL);

    g->start.lorel_max = 0;
    g->start.monster = sfClock_create();
    g->start.resume = sfSprite_copy(g->option.back.sprite);
    sfSprite_setTexture(g->start.resume, but1, sfTrue);
    sfSprite_setTextureRect(g->start.resume, rect);
    sfSprite_setPosition(g->start.resume, set_pos(1050, 800));
    g->start.t_resume = sfText_copy(g->option.t_back.text);
    sfText_setString(g->start.t_resume, "Resume");
    sfText_setPosition(g->start.t_resume, set_pos(1072, 800));
    g->start.nb_monster = 0;
    g->start.nb_text = 0;
    g->start.end = 0;
    g->start.pos = set_pos(0, 0);
    g->start.r_l = 0;
}

void init_start_two(game_t *g)
{
    g->start.d_attack = NULL;
    g->start.level = 0;
    g->achiev[4].actu--;
    g->start.t_lev = init_text("assets/fonts/ANY.ttf", 20
    , set_pos(400, 200), "0");
    g->start.bar = create_bar_hp();
    add_one_level(g);
    press_buttons(g, g->power_up.buy.sprite, 67, 1);
    sfMusic_stop(g->music.music[0]);
    g->start.dir = 1;
    g->start.lorel = 0;
    init_start_two_bis(g);
    intro_game(g);
}

void init_start_bis(game_t *g)
{
    g->start.d_text = NULL;
    g->start.d_attack = NULL;
    g->start.nb_attack = 0;
    g->start.nb_cryst = 0;
    g->start.nb_item = 0;
    g->start.or_win = 0;
    g->start.monster_kill = 0;
    g->start.pos = set_pos(0, 0);
    g->start.t_or = init_text("assets/fonts/ANY.ttf", 30,
    set_pos(1600, 70), "0");
    g->start.t_mons_kill = init_text("assets/fonts/ANY.ttf",
    30, set_pos(1400, 70), "0");
    g->start.t_pos_x = init_text("assets/fonts/ANY.ttf",
    30, set_pos(825, 150), "0");
    g->start.t_pos_y = init_text("assets/fonts/ANY.ttf",
    30, set_pos(1020, 150), "0");
}

void init_start(game_t *g, int cara)
{
    g->item_l = init_item(g);
    create_map(g);
    g->start.perso = g->stat_p[cara];
    g->start.tree = create_tree(g);
    add_stat_save(g, &g->start.perso);
    g->d_stat.t_stat = create_info_perso(g->stat_p[cara], g);
    cara = cara % 3;
    sfSprite_setTextureRect(g->start.perso.sprite.sprite,
    g->start.perso.rect[0]);
    g->start.clock = sfClock_create();
    g->start.regen = sfClock_create();
    g->start.clock_map = sfClock_create();
    create_inv(g, cara);
    g->start.xp = 0;
    g->start.d_monster = NULL;
    g->start.d_crys = NULL;
    init_start_bis(g);
    init_start_two(g);
}
