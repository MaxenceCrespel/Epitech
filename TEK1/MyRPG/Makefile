##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make file
##

SRC =	src/main.c \
		src/conditions/condition.c \
		src/conditions/condition1.c \
		src/conditions/condition2.c \
		src/conditions/condition4.c \
		src/conditions/condition5.c \
		src/conditions/condition6.c \
		src/conditions/condition7.c \
		src/conditions/condition8.c \
		src/conditions/condition9.c \
		src/helper.c \
		src/my_destroy.c \
		src/utility/utils.c \
		src/utility/utils2.c \
		src/create_map.c \
		src/function/ft_power_select.c \
		src/function/ft_verrif_click.c \
		src/function/ft_move_map.c \
		src/function/ft_calc_dir.c \
		src/function/ft_reaper.c \
		src/function/ft_attack.c \
		src/function/ft_attack2.c \
		src/function/ft_buttons.c \
		src/function/ft_buttons2.c \
		src/function/ft_buttons3.c \
		src/function/ft_flag.c \
		src/take_damage.c \
		src/draw/display_game.c \
		src/draw/draw_list.c \
		src/draw/draw_menu.c \
		src/draw/draw_settings.c \
		src/draw/draw_select_char.c \
		src/draw/draw_chose.c \
		src/draw/draw_spell.c \
		src/draw/draw_window.c \
		src/draw/draw_game.c \
		src/draw/draw_menu2.c \
		src/draw/draw_reaper.c \
		src/launch_game.c \
		src/langage.c \
		src/music/ft_music.c \
		src/music/init_sound.c \
		src/music/set_volume.c \
		src/initialize/init_game.c \
		src/initialize/init_start.c \
		src/initialize/init_start2.c \
		src/initialize/init_menu.c \
		src/initialize/init_save.c \
		src/initialize/init_save2.c \
		src/initialize/init_stat_chara.c \
		src/initialize/init_stat_chara2.c \
		src/initialize/init_stat_chara3.c \
		src/initialize/init_spell.c \
		src/initialize/init_spell2.c \
		src/initialize/init_spell3.c \
		src/initialize/init_icon.c \
		src/initialize/init_power_up.c \
		src/initialize/init_monster.c \
		src/initialize/init_monster2.c \
		src/initialize/init_monster3.c \
		src/create_stat_info.c \
		src/get_file_achiev.c \
		src/monster_attack.c \
		src/move_cara.c \
		src/intro_game.c \
		src/create_inv_empty.c \
		src/destroy_list.c \
		src/my_free.c \
		src/overlay.c \
		src/start_intro_game.c \
		src/overlay2.c \
		src/overlay3.c \
		src/intro_game2.c \
		src/create_tree.c \
		src/add_two_knife.c \
		src/click_power.c \

OBJ = 	$(SRC:.c = .o)

NAME =	my_rpg

CFLAGS += -I include/

all : $(NAME)

FLAGS =		-lcsfml-graphics \
			-lcsfml-audio \
			-lcsfml-window \
			-lcsfml-system

$(NAME):	$(SRC)
			make -C printf/
			gcc $(SRC) -L printf/ -lmy -o $(NAME) $(FLAGS) $(CFLAGS) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C printf/

re: fclean all
