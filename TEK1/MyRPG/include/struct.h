/*
** EPITECH PROJECT, 2022
** struct
** File description:
** defender
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Window.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <time.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>

typedef struct s_map {
    sfVector2f pos;
    sfIntRect rect;
    size_t len;
    FILE *fd;
    char *line;
    int nline;
} map;

typedef struct add_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    struct add_sprite_s *next;
} add_sprite;

typedef enum bin_e {
    true = 1,
    false = 0
} bin;

typedef struct my_sprite_s {
    sfSprite *sprite;
    sfVector2f *scale;
} my_sprite_t;

typedef struct bar_health_s {
    sfSprite *bg;
    sfSprite *front;
    sfRectangleShape *bar;
} bar_health;

typedef struct monster_s {
    int life;
    float speed;
    int damage;
    my_sprite_t sprite;
    sfIntRect *rect;
} monster_t;

typedef struct add_attack_s {
    my_sprite_t sprite;
    sfClock *time;
    int max_time;
    int status;
    int damage;
    int hit;
    sfVector2f dir;
    struct add_attack_s *next;
} add_attack_t;

typedef struct add_monster_s {
    int life;
    int type;
    float speed;
    int nb_rect;
    int damage;
    my_sprite_t sprite;
    sfIntRect *rect;
    sfClock *time;
    sfClock *atta;
    sfVector2f dir;
    struct add_monster_s *next;
} add_monster_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
} text_t;

typedef struct add_text_s {
    sfClock *time;
    sfVector2f pos;
    text_t damage;
    struct add_text_s *next;
} add_text_t;

typedef struct add_crist_s {
    my_sprite_t cryst;
    int type;
    int xp;
    struct add_crist_s *next;
} add_crist_t;

typedef struct win_s {
    my_sprite_t win;
    my_sprite_t wintext;
    my_sprite_t restart;
    my_sprite_t menu;
    my_sprite_t quit;
    sfClock *clockwin;
    sfRectangleShape *but1;
    sfRectangleShape *but2;
    sfRectangleShape *but3;
} win_t;

typedef struct g_menu_s {
    int select;
    int old_select;
    my_sprite_t bg;
    my_sprite_t vamp;
    my_sprite_t pers2;
    my_sprite_t pers;
    my_sprite_t start;
    text_t t_start;
    my_sprite_t option;
    text_t t_option;
    my_sprite_t quit;
    text_t t_quit;
    my_sprite_t help;
    text_t t_help;
    my_sprite_t power;
    text_t t_power;
    my_sprite_t achiev;
    text_t t_achiev;
    my_sprite_t logo;
    sfRectangleShape *but2;
    my_sprite_t coin;
    my_sprite_t img_coin;
    my_sprite_t font;
    text_t text;
    my_sprite_t over_bot;
} g_menu_t;

typedef struct g_pause_s {
    my_sprite_t bg;
    my_sprite_t continu;
    my_sprite_t settings;
    my_sprite_t menu;
    sfClock *clockpause;
    sfRectangleShape *but1;
    sfRectangleShape *but2;
    sfRectangleShape *but3;
} g_pause_t;

typedef struct select_s {
    my_sprite_t bg;
    my_sprite_t perso;
    text_t name;
    int have;
} select_t;

typedef struct save_s {
    int i_or;
    text_t t_or;
    int max_life;
    int ms;
    int area;
    int speed;
    int magnet;
    int recov;
    int armor;
    int cooldown;
    int pene;
    int growth;
    int duration;
    int *perso;
} save_t;

typedef struct stat_cara_s {
    my_sprite_t sprite;
    sfIntRect *rect;
    int dir;
    int life;
    int max_life;
    int ms;
    int area;
    int speed;
    int magnet;
    int recov;
    int armor;
    int cooldown;
    int pene;
    int growth;
    int duration;
} stat_cara_t;

typedef struct stat_attack_s {
    my_sprite_t vfx;
    my_sprite_t img;
    int max_time;
    int cooldown;
    int actif;
    int dama;
} stat_attack_t;

typedef struct slot_s {
    stat_attack_t att;
    int lvl;
    sfClock *clock;
    int status;
    int have;
} slot_t;

typedef struct inv_s {
    my_sprite_t bg;
    my_sprite_t empty_s;
} inv_t;

typedef struct item_s {
    my_sprite_t img;
    int have;
} item_t;

typedef struct game_loop_s {
    stat_cara_t perso;
    sfClock *clock;
    sfClock *clock_map;
    sfClock *regen;
    add_sprite *map;
    add_attack_t *d_attack;
    add_monster_t *d_monster;
    add_text_t *d_text;
    add_crist_t *d_crys;
    inv_t inv;
    sfClock *monster;
    slot_t *attack;
    item_t *item;
    int dir;
    int r_l;
    int xp;
    text_t t_lev;
    int level;
    int nb_attack;
    int nb_monster;
    int nb_cryst;
    int lorel;
    int or_win;
    int monster_kill;
    text_t t_or;
    text_t t_mons_kill;
    text_t t_pos_x;
    text_t t_pos_y;
    sfVector2f pos;
    bar_health bar;
    int lorel_max;
    sfSprite *resume;
    sfText *t_resume;
    sfRectangleShape *empty_bar;
    sfRectangleShape *bar_xp;
    int nb_text;
    int nb_item;
    int end;
    my_sprite_t *tree;
} game_loop_t;

typedef struct display_stat_s {
    my_sprite_t bg;
    stat_cara_t stat_p;
    text_t *stat_n;
    my_sprite_t *stat_i;
    text_t *t_stat;
} display_stat;

typedef struct chose_attack_s {
    my_sprite_t bg;
    sfSprite *img;
    int have;
    text_t name;
    text_t descri;
    text_t descri_new;
    text_t new;
} chose_attack_t;

typedef struct scene_up_s {
    my_sprite_t bg;
    text_t level_up;
    int nb1;
    chose_attack_t chose1;
    int nb2;
    chose_attack_t chose2;
    text_t info;
} scene_up_t;

typedef struct image_option_s {
    my_sprite_t img_opt;
    my_sprite_t oui;
    my_sprite_t non;
    text_t text;
    int status;
} image_option_t;

typedef struct option_s {
    my_sprite_t bg;
    my_sprite_t back;
    my_sprite_t quit;
    text_t t_quit;
    text_t t_back;
    image_option_t *img;
    int langage;
} option_t;

typedef struct create_select_power_up_s {
    my_sprite_t bg;
    my_sprite_t fond;
    my_sprite_t icon;
    my_sprite_t *square;
    my_sprite_t *oui;
    int have_nb;
    text_t name;
} create_select_power_up;

typedef struct power_up_s {
    create_select_power_up *list;
    create_select_power_up select;
    int display;
    text_t description;
    my_sprite_t buy;
    text_t t_buy;
    my_sprite_t coins;
    text_t price;
} power_up_t;

typedef struct achive_s {
    my_sprite_t img_opt;
    my_sprite_t oui;
    my_sprite_t non;
    text_t text;
    int actu;
    int max;
    int complete;
    text_t t_actu;
} achive_t;

typedef struct reaper_s {
    my_sprite_t reaper;
    int stop;
    sfClock *clock;
    int next;
    text_t *speak;
    sfRectangleShape *rect2;
    sfRectangleShape *rect1;
} reaper_t;

typedef struct list_it {
    my_sprite_t img;
    int status;
} list_it;

typedef struct music_s {
    sfMusic **music;
    int status;
} music_t;

typedef struct sound_s {
    sfSound **sound;
    sfSoundBuffer **buffer;
    int status;
} sound_t;

typedef struct lose_s {
    my_sprite_t over;
    my_sprite_t quit;
    my_sprite_t menu;
    text_t t_quit;
    text_t t_menu;
} lose_t;

typedef struct writer_s {
    text_t text;
    sfClock *clock;
    int status;
    int x;
} writer_t;

typedef struct overlay_s {
    my_sprite_t *gem;
    sfRectangleShape *empty_bar;
    sfRectangleShape *bar_xp;
    sfClock *clock;
    sfClock *clock2;
    int *y;
    int *x;
    float *scale;
    int color;
} overlay_t;

typedef struct intro_s {
    sfClock *clock;
    text_t text;
    int status;
} intro_t;

typedef struct helper_s {
    my_sprite_t help;
} helper_t;

typedef struct flag_s {
    my_sprite_t fr;
    my_sprite_t eng;
} flag_t;

typedef struct game_s {
    g_menu_t menu;
    stat_cara_t *stat_p;
    stat_attack_t *stat_attack;
    save_t save;
    scene_up_t level_up;
    select_t *select;
    reaper_t reaper;
    option_t option;
    game_loop_t start;
    achive_t *achiev;
    display_stat d_stat;
    monster_t *stat_m;
    power_up_t power_up;
    chose_attack_t *chose_attack;
    sfRenderWindow *window;
    my_sprite_t img_k_m;
    list_it *item_l;
    my_sprite_t arrow;
    sound_t sound;
    music_t music;
    int scene;
    int old_scene;
    sfVector2i mouse;
    int pause;
    my_sprite_t cursor;
    lose_t lose;
    writer_t writer;
    overlay_t lay;
    intro_t intro;
    helper_t help;
    flag_t flag;
} game_t;

#endif
