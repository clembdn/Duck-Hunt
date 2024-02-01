##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC	=	src/main.c 	\
		src/game.c	\
		src/init.c	\
		src/init2.c	\
		src/setting_menu.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CSFML =		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:		$(NAME)

$(NAME): 	$(OBJ)
			gcc -g3 $(SRC) -o $(NAME) -I ./include/ $(CSFML)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
