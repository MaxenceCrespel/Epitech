/*
** EPITECH PROJECT, 2021
** myH
** File description:
** stumper
*/

#ifndef MY_H
    #define MY_H
    #include "struct.h"
    #include "langage.h"
    #include <stdio.h>
    #include "../printf/include/my_printf.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <pwd.h>
    #include <grp.h>
    #include <string.h>
    #include <time.h>
    #include <unistd.h>
    #include <getopt.h>
    #include <fcntl.h>
    #include <string.h>
    #include <getopt.h>
    #include <sys/wait.h>
    #include <math.h>
    #include <tgmath.h>
    #define INTRO 0
    #define HIT 1
    #define KNIFE 2
    #define LEVEL_UP 3
    #define LOSE 4
    #define LOWHP 5
    #define PAUSE_IN 6
    #define PAUSE_OUT 7
    #define POWER_UP 8
    #define CLICK 9
    #define GAME 10
    #define POWER_UP2 11
    #define SLASH 12
    #define HPLOSE 13
    #define GEM 14
    #define MAGIC 15

static int ACHIEV_MAX[] = {100, 2500, 20000, 20, 50, 1000, 1000, 1000,
1000, 1000};

static char *NAME_SAVE[] = {"or", "Max_Health", "Recovery", "MoveSpeed",
"Armor", "Area", "Speed", "CoolDown", "Penetration",
"Duration", "Magnet", "Growth"};

/* create_inv_empty.c */
item_t *create_inv_empty(game_t *g);

/* create_map.c */
void init_map(map *m, char *maps);
int complete_sprite(add_sprite **actual, add_sprite *next_sprite\
, add_sprite *last);
void put_sprite(char *file, add_sprite **actual\
, sfVector2f pos, sfIntRect rect);
void create_map_nline(map *m, game_t *game, int i);
void create_map(game_t *game);

/* create_stat_info.c */
text_t *create_stat_name(void);
text_t *create_info_perso(stat_cara_t pr, game_t *g);
add_attack_t *new_fouet(game_t *g, int nb, add_attack_t *llist);

/* create_tree.c */
void display_arbre(game_t *g);
void move_tree(game_t *g, sfVector2f move);
int touch_tree(game_t *g, sfVector2f move);
my_sprite_t *create_tree(game_t *g);

/* destroy_list.c */
void destroy_list(add_monster_t **actual);

/* display_game.c */
int verrif_button_click(game_t *g, sfSprite *spr);
void click_menu(game_t *g);
int set_volume(game_t *g);
void click_option_two(game_t *g);
void click_option(game_t *g);

/* draw_list.c */
void click_select_two(game_t *g, int nb);
void click_select(game_t *g);
void change_stat(game_t *g, int attack);
void level_up_attack(game_t *g, int attack);
void add_attack(game_t *g, int attack);

/* draw_reaper.c */
void draw_reaper(game_t *g);

/* fichier1.c */
void click_lvl_up(game_t *g);
void copy_power_select_price(game_t *g, int nb);
void copy_power_select(game_t *g, int nb);
void augment_power(game_t *g, int nb);
void click_power(game_t *g);

/* fichier10.c */
void draw_slot_attack_def(game_t *g);
void draw_chose(game_t *g);
void draw_attack(game_t *g);
void display_text(game_t *g);
void draw_monster(game_t *g);

/* fichier11.c */
void display_img_attack(game_t *g);
void display_bar_life(game_t *g, bar_health bar);
void display_lorel(game_t *g, sfSprite *lorel, int nb);
void draw_cryst(game_t *g);
void display_game_two(game_t *g);

/* fichier12.c */
int init_cursor(game_t *g);
void refresh_cursor(game_t *g);
int init_lose(game_t *g);
int display_lose(game_t *g);
void draw_window(game_t *g);

/* fichier13.c */
void draw_item(game_t *g);
void draw_sprite_item(game_t *g);
void draw_info_text(game_t *g);
void draw_game_other_scene(game_t *g);
void display_game(game_t *g);

/* fichier14.c */
void draw_helper(game_t *g);
void draw_menu(game_t *g);
void draw_sprite(add_sprite *list, game_t *g);

/* fichier15.c */
void move_map(game_t *g, sfVector2f move);
void add_gold(game_t *g, int nb);
void fouet_dir(game_t *g, add_attack_t *element, int nb);
add_attack_t *new_attack(game_t *g, int nb, add_attack_t *llist);
void attack_zero(game_t *g);

/* fichier16.c */
void attack_un(game_t *g);
void attack_deux(game_t *g);
void remove_list_item(game_t *g);
void buy_perso(game_t *g);

/* fichier17.c */
int draw_option_mod(game_t *g);
void launch(game_t *g);
int write_nb_in_save(game_t *g, int nb);
void write_save(game_t *g);
void write_achiev(game_t *g);

/* fichier2.c */
void click_achiev(game_t *g);
void verrif_click(game_t *g);
void move(game_t *g);
void move_map2(add_sprite *plat, sfVector2f move);
void move_attack_map(add_attack_t *att, sfVector2f move);

/* fichier3.c */
void move_monster_map(add_monster_t *mons, sfVector2f move);
void move_text_map(add_text_t *mons, sfVector2f move);
void move_cryst_map(add_crist_t *mons, sfVector2f move);
void move_item_map(game_t *g, sfVector2f move);
void change_pos_game(game_t *g, sfVector2f move);

/* fichier4.c */
sfVector2f calc_dir_two(float stotck, sfVector2i dir);
sfVector2f calc_dir(sfVector2i dir, sfSprite *sprite);
void dir_dague(game_t *g, add_attack_t *element, int nb);

/* fichier5.c */
void draw_win(game_t *g, sfEvent event);
void boucle_talk_reaper(game_t *g, sfEvent event);
void talk_reaper(game_t *g, sfEvent event);
int sound_attack(game_t *g, int attack);
void event_game(game_t *g, sfEvent event);

/* fichier6.c */
void change_bar_hp(bar_health bar, int value, int max_value);
void take_damage(game_t *g, int nb);
int sound_pause(game_t *g);
void event_key_two(game_t *g, sfEvent event);
void event_key(game_t *g, sfEvent event);

/* fichier7.c */
void my_event(game_t *g, sfEvent event);
void draw_scene_zero(game_t *g);
void draw_stat_p(game_t *g);
void draw_stat_in(game_t *g);
void draw_option_case(game_t *g, int i);

/* fichier8.c */
void draw_option(game_t *g);
void draw_descri_power(game_t *g);
void draw_img_descri(game_t *g, int i);
void draw_power_up(game_t *g);
void draw_price(game_t *g);

/* fichier9.c */
void draw_buy_or_selct(game_t *g, sfSprite *cpy, sfText *two);
void draw_over_select(game_t *g);
void draw_slt_perso(game_t *g, int i);
void draw_select_perso(game_t *g);
void draw_achiev(game_t *g);

/* ft_buttons.c */
void verrif_button(game_t *g, sfSprite *sprite, sfIntRect rect);
void animate_buttons(game_t *g);
int press_buttons(game_t *g, sfSprite *sprite, int top, int scene);
void verrif_mouse_menu(game_t *g);

/* get_file_achiev.c */
void init_save_achiev(achive_t *list);
int get_achiev_actu(char *cmd, game_t *g);
void verif_file_achiev(char *buffer, game_t *g, achive_t *list);

/* helper.c */
void helper2(void);
void helper(void);
int display_help(void);

/*__________initialize__________*/

/* init_game.c */
void init_game_two(game_t *g);
void click_help(game_t *g);
void init_helper(game_t *g);
void init_game(game_t *g);

/* init_start.c */
bar_health create_bar_hp(void);
void init_start_two_bis(game_t *g);
void init_start_two(game_t *g);
void init_start_bis(game_t *g);
void init_start(game_t *g, int cara);

/* init_start2.c */
int stat_calc(float pers, int save, int pour);
void add_stat_save(game_t *g, stat_cara_t *perso);
slot_t *create_slot_attack(game_t *g, int nb);
void create_slot_empty(game_t *g, int nb);
void create_inv(game_t *g, int nb);

/* init_menu.c */
void create_window(game_t *g);
void create_menu3(game_t *g);
void create_menu2(game_t *g, sfIntRect rect, sfTexture *bg);
void create_menu(game_t *g);

/* init_save.c */
void create_stat_icon_two(my_sprite_t *stat, sfTexture *bg, sfVector2f vec);
my_sprite_t *create_stat_icone(void);
void create_select_bg(game_t *g);
void init_save(game_t *g);

/* init_save2.c */
int verrif_len_line_save(char *cmd, game_t *g);
void set_list_in_save(game_t *g, int list[]);
void get_perso(game_t *g, char *str);
void verif_file(char *buffer, game_t *g);
void get_save(game_t *g);

/* init_stat_chara.c */
sfIntRect *select_rect(void);
void create_select_boucle(select_t *select, int i, sfIntRect *rect, game_t *g);
select_t *create_select_perso(game_t *g);
void stat_cara_un2(stat_cara_t *stat);
stat_cara_t stat_cara_un(void);

/* init_stat_chara2.c */
void stat_cara_two2(stat_cara_t *stat);
stat_cara_t stat_cara_two(void);
void stat_cara_three2(stat_cara_t *stat);
stat_cara_t stat_cara_three(void);
void stat_cara_four2(stat_cara_t *stat);

/* init_stat_chara3.c */
stat_cara_t stat_cara_four(void);
void stat_cara_five2(stat_cara_t *stat);
stat_cara_t stat_cara_five(void);
void stat_cara_six2(stat_cara_t *stat);
stat_cara_t stat_cara_six(void);

/* init_spell.c */
stat_cara_t *create_stat_perso(game_t *g);
stat_attack_t create_attack_fouet(void);
stat_attack_t create_attack_fire(void);
stat_attack_t create_attack_couteau(void);
stat_attack_t create_attack_lorel(void);

/* init_spell2.c */
stat_attack_t create_attack_ms(void);
stat_attack_t create_attack_cooldown(void);
stat_attack_t *create_attack_stat(void);
void create_scene_up(game_t *g);
chose_attack_t create_chose_fouet(game_t *g);

/* init_spell3.c */
chose_attack_t create_chose_fire(game_t *g);
chose_attack_t create_chose_couteau(game_t *g);
chose_attack_t create_chose_lorel(game_t *g);
chose_attack_t create_chose_ms(game_t *g);
chose_attack_t create_chose_cooldown(game_t *g);

/* init_icon.c */
chose_attack_t *create_chose_attack(game_t *g);
image_option_t *create_option_img(game_t *g);
void create_option(game_t *g);
sfIntRect *select_rect_icon(void);
my_sprite_t *create_small_square(sfVector2f pos);

/* init_power_up.c */
my_sprite_t *create_small_yes(sfVector2f pos);
void create_power_up_list2(create_select_power_up *list, int i,
sfIntRect *rect, sfVector2f p);
create_select_power_up *create_power_up_list(game_t *g);

/* init_monster.c */
void get_save_achiev(game_t *g, achive_t *list);
void check_complete(achive_t *list);
achive_t *create_achiev(game_t *g);
void create_power_up(game_t *g);
monster_t create_monster_un(game_t *g);

/* init_monster2.c */
monster_t create_monster_two(game_t *g);
monster_t create_monster_tree(game_t *g);
monster_t create_monster_four(game_t *g);
monster_t create_monster_five(game_t *g);
monster_t create_monster_six(game_t *g);

/* init_monster3.c */
monster_t create_monster_sev(game_t *g);
monster_t create_monster_heig(game_t *g);
monster_t *create_monster(game_t *g);
sfVector2f random_pos_item(void);
list_it *init_item(game_t *g);

/* intro_game.c */
void event_intro(game_t *g, sfEvent event);
void change_rect_reaper(game_t *g);
void move_reaper(game_t *g);
void intro_game(game_t *g);

/* intro_game2.c */
text_t *create_talk_reaper(game_t *g);
void create_reaper(game_t *g);
void event_intro2_bis(game_t *g, sfEvent event);
void event_intro2(game_t *g, sfEvent event);
void event_intro3(game_t *g, sfEvent event);

/* langage.c */

void change_language(game_t *g);
void event_key_three(game_t *g, sfEvent event);

/* main.c */
int main(int ac, char **av);

/* monster_attack.c */
int monster_move(game_t *g, add_monster_t *tmp);
void monster_attack(game_t *g, add_monster_t *tmp);

/* move_cara.c */
int can_move(game_t *g, sfVector2f mov);
void event_move4(game_t *g, int speed);
void event_move3(game_t *g, int speed);
void event_move2(game_t *g);
void event_move(game_t *g);

/*____________music____________*/

/* ft_music.c */
int init_music(game_t *g);
int ft_setloop(game_t *g);
int init_sfx(game_t *g);
int destroy_sound(game_t *g);

/* init_sound.c */
void ft_soundbuffer_two(game_t *g);
int ft_soundbuffer(game_t *g);
int ft_sound(game_t *g);
int init_sound(game_t *g);
int ft_setbuffer(game_t *g);

/* set_volume.c */
int sound_on(game_t *g);
int sound_off(game_t *g);
int music_on(game_t *g);
int music_off(game_t *g);
int ft_volume(game_t *g);

/* my_destroy.c */
void my_destroy_all(game_t *g);

/* my_free.c */
void free_array(char **array);
void free_triple_array(char ***array);
int my_free(void *ptr);

/* overlay.c */
int loop_set_color(game_t *g);
int animate_gem(game_t *g);
int loop_initer_gem(game_t *g);
int display_overlay(game_t *g);

/* overlay2.c */
int *random_x(game_t *g, int max, int min, int num);
int *random_y(game_t *g, int max, int min, int num);
sfTexture **init_texture_gem2(sfTexture **texture);
sfTexture **init_texture_gem(game_t *g);
float *my_tab_of_float(float nb, int length);

/* overlay3.c */
int init_bar_loop(game_t *g);
int init_sprite_gem(game_t *g);
int init_overlay_gem(game_t *g);
int animate_gem_end(game_t *g, int i, float minus, sfTime time);
int loop_set_color_end(game_t *g);

/* start_intro_game.c */
char *str_mod(game_t *g, char *str, int i);
int animate_text(game_t *g, char *str);
int init_start_intro(game_t *g);
int blinking_text(game_t *g);
void draw_start_intro(game_t *g);

/*___________utility___________*/

/* utils.c */
my_sprite_t set_sprite(sfTexture *texture, sfVector2f pos, sfVector2f scale);
my_sprite_t set_sprite_rect(sfTexture *texture, sfVector2f pos,
sfVector2f scale, sfIntRect rect);
sfRectangleShape *create_button(sfVector2f pos, sfVector2f size);
text_t init_text(char *path, int nb, sfVector2f pos, char *str);
int verrif_button_rect(game_t *g, sfRectangleShape *spr);

/* utils2.c */
sfText *put_text(sfVector2f pos, int size, char *msg);
sfColor ini_color(int r, int g, int b, int a);
int *my_intdup(int *cp, int len);
sfVector2f set_pos(float x, float y);
sfIntRect pos_rect(int top, int left, int width, int height);

/* ft_buttons2.c */
void verrif_mouse_select(game_t *g);
void verrif_mouse_achiev(game_t *g);
void verrif_mouse_power(game_t *g);
void verrif_mouse_option(game_t *g);

/*__________conditions__________*/

/* condition.c */
void remove_monster_bis(game_t *g, add_monster_t **actuel,
add_monster_t *attack, add_monster_t *prev);
void remove_monster(game_t *g, add_monster_t **actuel);
void move_monster(game_t *g);
void move_attack(game_t *g);
void conditions_scene(game_t *g);

/* condition1.c */
void verrif_new_attack(game_t *g);
void change_next_chose(game_t *g);
void add_one_level(game_t *g);
void delete_attack(add_attack_t **attack, add_attack_t *prev,
add_attack_t **list, game_t *g);
void delete_text(add_text_t **attack, add_text_t *prev, add_text_t **list);

/* condition2.c */
void delete_monster(add_monster_t **attack, add_monster_t *prev,
add_monster_t **list);
add_text_t *new_text_damage(game_t *g, add_text_t *llist,
add_attack_t *tmp, add_monster_t *mons);
void monster_take_damage(game_t *g, add_monster_t *tmp, add_attack_t *att);
int verrif_hit(add_attack_t *tmp, game_t *g);
void verrif_delete_attack(game_t *g, add_attack_t **actuel);

/* condition4.c */
void delete_cryst(add_crist_t **attack, add_crist_t *prev, add_crist_t **list);
void add_xp(game_t *g, int nb);
void recup_cryst(game_t *g, add_crist_t **actuel);
sfIntRect get_rect_cryst(int nb);
add_crist_t *create_cryst(game_t *g, add_crist_t *llist, add_monster_t *mons);

/* condition5.c */
sfVector2f calc_path_monster2(float speed, float stotck,
sfVector2f pos_actual);
sfVector2f calc_path_monster(game_t *g, sfSprite *actual, float speed);
int monst_can_move(game_t *g, add_monster_t *tmp);
int get_rotate(int nb);

/* condition6.c */
void verrif_have_attack2(game_t *g, int cmp, int nb, int i);
void verrif_have_attack(game_t *g);
void quit_game(game_t *g);
void verrif_lose(game_t *g);
sfVector2f get_pos_monster(void);

/* condition7.c */
int mirror_perso(game_t *g);
void data_game(game_t *g);
void data_menu(game_t *g);

/* condition8.c */
void remove_text(game_t *g, add_text_t **actuel);
void regen_life(game_t *g);
add_monster_t *add_monster(game_t *g, int nb, add_monster_t *llist);
void spawn_monster(game_t *g);
int mirror_monster(game_t *g);

/* condition9.c */
void data_game2(game_t *g);
void add_slot_item(game_t *g, int nb);
void verif_recup_item(game_t *g);
int set_pos_arrow_obj(game_t *g, sfVector2f pos);
void see_dir_ob(game_t *g);

/* ft_buttons3.c */
void click_lose(game_t *g);
void verrif_mouse_lose(game_t *g);

/* add_two_knife.c */
add_attack_t *new_knife(game_t *g, int nb, add_attack_t *llist);

/* ft_flag.c */
void init_flag(game_t *g);
void draw_flag(game_t *g);
void click_flag(game_t *g);
void verrif_flag(game_t *g, sfSprite *sprite, sfVector2f pos);
void in_flag(game_t *g);

#endif
