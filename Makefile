#MAIN VARS
CC 				= cc -g

CFLAGS 			= -Wall -Wextra -Werror 

MINILIBX_DIR 	= ./minilibx-linux

NAME 			= so_long

BONUS_NAME		= so_long_bonus

FUNC_DIR		= functions/

#FILES NAME
MAIN_FILE		= so_long.c

FUNC_FILES 		= so_long_game.c \
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

FUNC            = $(addprefix $(FUNC_DIR), $(FUNC_FILES))

#OBJECTS
MAIN_OBJ		= $(MAIN_FILE:%.c=output/%.o)
FUNC_OBJS 		= $(FUNC:$(FUNC_DIR)%.c=output/%.o)

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
	if [ "$(1)" != "fclean" ]; then \
        make $(1) -C $(MINILIBX_DIR); \
    fi
endef

define Makebin
	$(call MakeLibs,all)
	$(CC) $(CFLAGS) $(1) $(LIBS) -o $(2)
endef

#MAIN RULES
all: $(NAME)

output/%.o: %.c | output
	$(call Compile,$<,$@)

output/%.o: $(FUNC_DIR)%.c | output
	$(call Compile,$<,$@)

$(NAME) : $(MAIN_OBJ) $(FUNC_OBJS)
	$(call Makebin,$^,$@)

clean:
	$(call MakeLibs,clean)
	rm -rf output/*.o

fclean: clean
	$(call MakeLibs,fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re