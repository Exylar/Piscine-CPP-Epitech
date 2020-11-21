##
## EPITECH PROJECT, 2019
## CPool_rush2_2019
## File description:
## Makefile
##

SRC	=	main.cpp	\
		../src/XMLParser.cpp	\
		../src/Object.cpp	\
		../src/Wrap.cpp	\
		ArgsParser.cpp	\
		Santa.cpp	\
		../src/Toy.cpp	\
		../src/Teddy.cpp	\
		../src/LittlePony.cpp	\
		../src/Box.cpp	\
		../src/GiftPaper.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall \
	-Wextra \
	-Werror \
	-I $(INCLUDE)

INCLUDE =	../include

NAME	=	santa

all: $(NAME)

$(NAME): $(OBJ)
	 g++ -o $(NAME) $(CXXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
