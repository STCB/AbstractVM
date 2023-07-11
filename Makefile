##
## EPITECH PROJECT, 2023
## abstractVM
## File description:
## Makefile
##

CXXFLAGS    +=    -Wall -Wextra -Wpedantic -Iinclude

SRC			:=		source/main.cpp				\
					source/Double.cpp			\
					source/Factory.cpp			\
					source/Float.cpp			\
					source/Int8.cpp				\
					source/Int16.cpp			\
					source/Int32.cpp			\
					source/Interpreter.cpp		\
					source/stack.cpp			\
					source/Register.cpp			\

OBJ				:=    $(SRC:.cpp=.o)

NAME			:=    abstractVM

all:        $(NAME)

run:        $(NAME)
			./$(NAME)

$(NAME):    $(OBJ)
			$(CXX) -o $@ $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean
			$(MAKE)

debug:		fclean
			CXXFLAGS=-g3 $(MAKE)

val:		debug
			valgrind -s ./$(NAME)

valtest:		debug
			valgrind -s --show-leak-kinds=all --leak-check=full ./$(NAME) test

.PHONY:        all clean fclean re debug val
