##
## EPITECH PROJECT, 2019
## cpp_d01_2019
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/menger.c	\
		src/drawing.c	\
		src/bitmap_header.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	menger_face

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -std=gnu11 -Wall -Wextra

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
