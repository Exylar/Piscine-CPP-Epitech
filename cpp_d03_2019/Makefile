##
## EPITECH PROJECT, 2019
## CPool_Day010_2019
## File description:
## Makefile
##

SRC 	=	append.c	\
		assign.c	\
		compare.c	\
		copy.c	\
		find.c	\
		init.c	\
		insert.c	\
		join.c	\
		split.c	\
		substr.c	\
		utils.c	\
		utils2.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) -std=gnu11 -Wall -Wextra
	ar rc $(NAME) $(OBJ)
	make -C tests/ tests_run

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
