##
## EPITECH PROJECT, 2020
## cpp_d13_2019
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
DEFAULT_C	=	"\e[39m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

SRC 	=	ex06/Buzz.cpp	\
		ex06/Picture.cpp	\
		ex06/Toy.cpp	\
		ex06/ToyStory.cpp	\
		ex06/Woody.cpp

SRC_TESTS    =	tests/test_pictures.cpp

NAME 	= 	unit_tests

CXXFLAGS	=	-Wall \
		-Wextra \
		-Werror	\
		-I ./ex06

CXXFLAGS	+=  	--coverage

SRCS	=	$(SRC) $(SRC_TESTS)

OBJ	=	$(SRC:.cpp=.o)

OBJ_TESTS = 	$(SRCS:.cpp=.o)


all: 	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _   _       _ _     _____         _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| | | |_ __ (_) |_  |_   _|__  ___| |_ ___"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| | | | '_ \| | __|   | |/ _ \/ __| __/ __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)'| |_| | | | | | |_    | |  __/\__ \ |_\__ \\'$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" \___/|_| |_|_|\__|   |_|\___||___/\__|___/\n"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME):	tests_run

tests_run: $(OBJ_TESTS)
	@$(CXX) -o $(NAME) $(OBJ_TESTS) $(CXXFLAGS) -lcriterion
	@$(LINE_RETURN)
	@./unit_tests
	@$(LINE_RETURN)
	@gcovr --exclude tests --print-summary
	@$(LINE_RETURN)

clean:
	@rm -rf $(OBJ)
	@rm -rf ex06/*.gcda
	@rm -rf ex06/*.gcno
	@rm -rf tests/*.gcda
	@rm -rf tests/*.gcno

fclean:	clean
	@rm -f $(NAME)

re:	all

.PHONY: all tests_run clean fclean re message
