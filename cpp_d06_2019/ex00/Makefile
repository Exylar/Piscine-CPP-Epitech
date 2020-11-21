##
## EPITECH PROJECT, 2019
## cpp_d06_2019
## File description:
## Makefile
##

SRC	=	my_cat.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_cat

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) -Wall -Wextra -Werror

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
