##
## EPITECH PROJECT, 2020
## cpp_rush2_2019
## File description:
## Makefile
##

NAME	=	xml_parser
INCLUDE	=	../../include/

SRC	=	../../src/Box.cpp \
		../../src/ConveyorBeltRand.cpp \
		../../src/GiftPaper.cpp \
		../../src/Hand.cpp \
		../../src/LittlePony.cpp \
		../../src/MagicalCarpet.cpp \
		../../src/Object.cpp \
		../../src/PapaXmasConveyorBelt.cpp \
		../../src/PapaXmasElf.cpp \
		../../src/PapaXmasTable.cpp \
		../../src/TableRand.cpp \
		../../src/Teddy.cpp \
		../../src/Toy.cpp \
		../../src/Wrap.cpp \
		../../src/XMLParser.cpp

SRCS	=	$(SRC) main_parser.cpp

CXXFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	=	-I $(INCLUDE)
OBJ	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(CXXFLAGS) -I $(INCLUDE) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

debug: CXXFLAGS += -g
debug: all

.PHONY:	all clean fclean re debug
