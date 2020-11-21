##
## EPITECH PROJECT, 2020
## cpp_rush1_2019
## File description:
## Makefile
##

NAME	=	unit_tests

INCLUDE_DIR	=	../include/

SRC	=	../santa/Santa.cpp	\
		../src/Box.cpp \
		../src/ConveyorBeltRand.cpp \
		../src/GiftPaper.cpp \
		../src/Hand.cpp \
		../src/LittlePony.cpp \
		../src/MagicalCarpet.cpp \
		../src/Object.cpp \
		../src/PapaXmasConveyorBelt.cpp \
		../src/PapaXmasElf.cpp \
		../src/PapaXmasTable.cpp \
		../src/TableRand.cpp \
		../src/Teddy.cpp \
		../src/Toy.cpp \
		../src/Wrap.cpp \
		../src/XMLParser.cpp	\
		../santa/ArgsParser.cpp

SRC_TESTS	=	./test_my_santa.cpp	\
				./test_my_args_parser.cpp	\
				./test_my_elf.cpp

SRCS	=	$(SRC) $(SRC_TESTS)

OBJ	=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -Werror --coverage -I $(INCLUDE_DIR)

LDFLAGS	=	-lcriterion

tests_run: $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)
	@./$(NAME)
	@gcovr --root .. --exclude tests/ --exclude ../include

re:	fclean tests_run

clean:
	@$(RM) $(OBJ)
	@$(RM) $(SRCS:.cpp=.gcno)
	@$(RM) $(SRCS:.cpp=.gcda)

fclean:	clean
	@$(RM) $(NAME)

.PHONY:	tests_run re clean fclean
