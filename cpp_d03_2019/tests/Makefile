##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## Fairefichier that does the tests_run rule
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

NAME	=	unit_tests

ROOT_PATH	=	./
TESTS_NAME	=	tests
INCL_PATH	=	$(ROOT_PATH)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
SRC_PATH	=	$(ROOT_PATH)

SRC     =       ../append.c        \
                ../assign.c        \
                ../compare.c       \
                ../copy.c  \
                ../find.c  \
                ../init.c  \
                ../insert.c        \
                ../join.c  \
                ../split.c \
                ../substr.c        \
                ../utils.c \
                ../utils2.c


SRC_TESTS    =  test_append.c	\
		test_assign.c	\
		test_at.c	\
		test_c_str.c	\
		test_compare.c	\
		test_copy.c	\
		test_empty.c	\
		test_find.c	\
		test_init.c	\
		test_utils.c	\
		test_insert.c   \
		test_to_int.c   \
		test_split.c    \
		test_join.c \
		test_substr.c   \
		test_substr2.c

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_TESTS)
OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall \
			-Wextra \
			-Werror \
			-I $(INCL_PATH)

CFLAGS	+=	-lcriterion \
			--coverage

tests_run:	message fclean $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _   _       _ _     _____         _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| | | |_ __ (_) |_  |_   _|__  ___| |_ ___"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| | | | '_ \| | __|   | |/ _ \/ __| __/ __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)'| |_| | | | | | |_    | |  __/\__ \ |_\__ \\'$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" \___/|_| |_|_|\__|   |_|\___||___/\__|___/\n"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(SRCS) $(CFLAGS)
	@./$(NAME)
	@gcovr --exclude "./" --print-summary
	@$(ECHO) $(DEFAULT)

clean:
	@$(RM) $(OBJ)
	@$(RM) ../*.gcno
	@$(RM) ../*.gcda
	@$(RM) *.gcno
	@$(RM) *.gcda

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all

.PHONY: all message clean fclean re
