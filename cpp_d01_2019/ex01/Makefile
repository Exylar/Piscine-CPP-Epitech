##
## EPITECH PROJECT, 2019
## cpp_d01_2019
## File description:
## Makefile
##

SRC	=	main.c	\
		menger.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -std=gnu11 -Wall -Wextra

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
