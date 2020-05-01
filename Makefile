##
## EPITECH PROJECT, 2019
## MyRPG
## File description:
## Makefile
##

SRC = $(shell find . -name '*.c')

OUT = my_rpg

CFLAGS = -lm -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -I./include -Wall -W

CC = gcc

OBJ	=	$(SRC:.c=.o)

all: $(OUT)

$(OUT):	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS)
	make clean

clean:
	$(shell find . -name '*.o' -delete)

fclean:	clean
	$(RM) -rf $(OUT)

re: fclean $(OUT)