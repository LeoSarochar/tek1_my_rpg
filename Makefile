##
## EPITECH PROJECT, 2019
## MyRPG
## File description:
## Makefile
##

SRC = $(shell find . -name '*.c')
OUT = my_rpg
CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -I./include -Wall -W

$(OUT): re

clean:
	rm -rf *.o

fclean:
	$(clean)
	rm -rf $(OUT)

re: fclean
	gcc $(SRC) $(CFLAGS) -o $(OUT)