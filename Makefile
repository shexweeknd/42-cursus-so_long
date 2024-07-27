FLAGS = -Wall -Wextra -Werror 

MINILIBX_DIR = ./minilibx-linux

NAME = so_long

BONUS_NAME = so_long_bonus

SRCS = so_long.c \
		so_long_game.c \
		so_long_game_utils.c \
		so_long_render.c \
		so_long_hooks.c \
		so_long_error.c \
		so_long_debug.c \
		so_long_ber.c \
		so_long_ber_utils.c \
		so_long_grid_rules.c \
		so_long_pce_rules.c \
		so_long_wall_rules.c \
		so_long_way_rules.c \

BONUS_SRCS = so_long.c \
		so_long_game_utils.c \
		so_long_render.c \
		so_long_hooks.c \
		so_long_error.c \
		so_long_debug.c \
		so_long_ber.c \
		so_long_ber_utils.c \
		so_long_grid_rules.c \
		so_long_pce_rules.c \
		so_long_wall_rules.c \
		so_long_way_rules.c \
		so_long_game_bonus.c \
		so_long_anim_one_bonus.c \
		so_long_anim_two_bonus.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	@cc -c -g $(FLAGS) $(SRCS) $(BONUS_SRCS) -I ./ -I ./libft/ -I ./libft/ft_printf/ -I ./minilibx-linux

all: $(NAME)

$(NAME) : $(OBJS)
	@cd minilibx-linux &&\
	make &&\
	cd ..
	@cd libft &&\
	make &&\
	cd ..
	@cc $(FLAGS) -g $(OBJS) -o $(NAME) -L./minilibx-linux -lmlx_Linux -lX11 -lXext -lm \
	-L./libft -lft \

bonus: $(BONUS_OBJS)
	@cd minilibx-linux &&\
	make &&\
	cd ..
	@cd libft &&\
	make &&\
	cd ..
	@cc $(FLAGS) -g $(BONUS_OBJS) -o $(BONUS_NAME) -L./minilibx-linux -lmlx_Linux -lX11 -lXext -lm \
	-L./libft -lft \

clean: $(OBJS) $(BONUS_OBJS)
	@cd minilibx-linux &&\
	make clean &&\
	cd ..
	@cd libft &&\
	make clean &&\
	cd ..
	@echo $(OBJS) $(BONUS_OBJS)
	@rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@cd libft &&\
	make fclean &&\
	cd ..
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean
	@make all

.PHONY: clean fclean all re