#MAIN VARS
CC 				= cc -g

CFLAGS 			= -Wall -Wextra -Werror 

MINILIBX_DIR 	= ./minilibx-linux

NAME 			= so_long

BONUS_NAME		= so_long_bonus

#FILES NAME
SRC 			= so_long.c

FUNC 			= so_long_game.c \
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

BONUS_FUNC 		= so_long_game_utils.c \
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

#OBJECTS
OBJS			= $(SRC:%.c=output/%.o)
FUNC_OBJS 		= $(FUNC:%.c=output/%.o)
FUNC_BONUS_OBJS = $(BONUS_FUNC:%.c=output/.o)

#DEPENDECIES
LIBFT_DIR 		= libft

#LIBRARIES
LIBFT_LIB		= -L$(LIBFT_DIR) -lft
MINILIBX_LIB	= -L$(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext -lm
LIBS 			= $(LIBFT_LIB) $(MINILIBX_LIB)

#INCLUDES
LIBFT_INC		= -I$(LIBFT_DIR)/includes
MINILIBX_INC	= -I$(MINILIBX_DIR)/
SO_LONG_INC		= -Iincludes
INCLUDES		= $(LIBFT_INC) $(SO_LONG_INC) $(MINILIBX_INC)

#MAKE FUNCTIONS
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define MakeLibs
	make $(1) -C $(LIBFT_DIR)
endef

define Makebin
	$(call MakeLibs,all)
	$(CC) $(CFLAGS) $(LIBS) $(1) -o $(2)
endef

#MAIN RULES
all: $(NAME)

output/%.o	: %.c | output
				$(call Compile,$<,$@)

output/%.o	: functions/%.c | output
				$(call Compile,$<,$@)

$(NAME) : $(OBJS) $(FUNC_OBJS)
	$(call Makebin,$^,$@)

clean: $(OBJS) $(FUNC_OBJS) $(BONUS_OBJS)
	$(call MakeLibs,clean)
	rm -rf $(OBJS) $(FUNC_OBJS) $(BONUS_OBJS)

fclean: clean
	$(call MakeLibs,fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re