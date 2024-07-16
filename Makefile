FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = \

SRC_BONUS = \

all: $(NAME)

$(NAME) : 

.c.o:
	@cc -c -g $(FLAGS) $(SRC) $(SRC_BONUS) -I ./ -I ./ft_printf/

clean:
fclean:
re:
bonus:

.PHONY: clean fclean all re bonus
