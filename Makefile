##
## EPITECH PROJECT, 2018
## matchstick
## File description:
## Makefile
##

SRC	=	main.c	\
		utils.c	\
		board.c	\
		matches.c	\
		my_getnbr.c	\
		ai_functions.c	\
		player_turn.c	\
		error_functions.c	\

NAME	=	matchstick

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-g

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my_printf
	$(CC) -o $(NAME) $(OBJ) -I include/ -L lib -l printf -W -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)
	make clean -C lib/my_printf

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my_printf

re: fclean all
