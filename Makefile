##
## EPITECH PROJECT, 2019
## MyRPG
## File description:
## Makefile
##

SRC = $(shell find . -name '*.c')

OUT = my_rpg

CFLAGS = -lm -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -I./include -Wall -W

CFLAGS_DEBUG =

CC = gcc -g3

OBJ	=	$(SRC:.c=.o)

$(OUT): re

debug:	compile_debug

compile:	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)
	make clean

compile_debug:	CFLAGS += $(CFLAGS_DEBUG)

compile_debug:	fclean	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)

clean:
	$(shell find . -name '*.o' -delete)

fclean:	clean
	$(RM) -rf $(OUT)

re: fclean compile