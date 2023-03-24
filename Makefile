##
## EPITECH PROJECT, 2022
## MyRPG
## File description:
## Makefile
##

SRC =	$(shell find m_rect -name '*.c')			\
		$(shell find m_rtex -name '*.c')			\
		$(shell find m_sprite -name '*.c')			\
		$(shell find m_circle -name '*.c')			\
		$(shell find m_text -name '*.c')			\
		$(shell find m_vertex -name '*.c')			\
		$(shell find m_bar -name '*.c')				\
		$(shell find m_button -name '*.c')			\
		$(shell find m_config -name '*.c')			\
		$(shell find m_container -name '*.c')		\
		$(shell find m_element_utils -name '*.c')	\
		$(shell find m_input -name '*.c')			\
		$(shell find m_object -name '*.c')			\
		$(shell find m_pre_init -name '*.c')		\
		$(shell find m_render -name '*.c')			\
		$(shell find m_slider -name '*.c')			\
		$(shell find m_switch -name '*.c')			\
		$(shell find m_transform -name '*.c')		\
		$(shell find m_utils -name '*.c')			\
		$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	app

CSFML = -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system -lm

all:	$(NAME)

library:
	make -C lib/my

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) -O3 lib/libmy.a

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all

.PHONY: all clean fclean re
