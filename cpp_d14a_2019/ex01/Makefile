##
## EPITECH PROJECT, 2010
## cpp_d14a_2019
## File description:
## Makefile
##


SRC = \
	  AtmosphereRegulator.cpp \
	  Engine.cpp \
	  Errors.cpp \
	  Oxygenator.cpp \
	  RoverUnitTests.cpp \
	  WaterReclaimer.cpp

CXX = g++
CXXFLAGS = -W -Wall -Wextra
LDFLAGS =
NAME = RoverUnit

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test
