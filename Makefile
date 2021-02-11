##
## EPITECH PROJECT, 2020
## OOP_nanotekspice_2019
## File description:
## Makefile
##

CC	=	g++

SRC	=	$(wildcard *.cpp */*.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = nanotekspice

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bin:	all
	rm -rf $(OBJ)