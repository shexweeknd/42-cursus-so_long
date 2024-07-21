FLAGS = -Wall -Wextra -Werror 

NAME = so_long

SRCS = so_long.c \
		so_long_render.c \
		so_long_closing.c \
		so_long_error.c \
		so_long_debug.c \
		so_long_grid_rules.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	@cc -c -g $(FLAGS) $(SRCS) -I ./ -I ./libft/ -I ./libft/ft_printf/ -I ./minilibx-linux

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

clean: $(OBJS)
	@cd minilibx-linux &&\
	make clean &&\
	cd ..
	@cd libft &&\
	make clean &&\
	cd ..
	@echo $(OBJS)
	@rm -rf $(OBJS)

fclean: clean
	@cd libft &&\
	make fclean &&\
	cd ..
	@rm -rf $(NAME)

re: fclean
	@make all

.PHONY: clean fclean all re