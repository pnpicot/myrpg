##
## EPITECH PROJECT, 2022
## Libmy's Makefile
## File description:
## Libmy's Makefile
##

SRC	=	$(shell find my_printf -name '*.c')			\
		$(shell find linked_lists -name '*.c')		\
		$(shell find files -name '*.c')				\
		$(shell find strings -name '*.c')			\
		$(shell find numbers -name '*.c')			\
		$(shell find error_handling -name '*.c')	\
		$(shell find display_fns -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME) clean

$(NAME):	$(OBJ)
	gcc -c $(OBJ)
	ar rcs $(NAME) $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
