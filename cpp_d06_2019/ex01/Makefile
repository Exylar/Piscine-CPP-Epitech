##
## EPITECH PROJECT, 2019
## cpp_d06_2019
## File description:
## Makefile
##

SRC	=	my_convert_temp.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_convert_temp

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) -Wall -Wextra -Werror

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
