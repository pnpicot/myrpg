##
## EPITECH PROJECT, 2022
## Libmy's Makefile
## File description:
## Libmy's Makefile
##

MAIN 	  	:= libmy.a
SRCS		:=	$(shell find my_printf -name '*.c')			\
				$(shell find linked_lists -name '*.c')		\
				$(shell find files -name '*.c')				\
				$(shell find strings -name '*.c')			\
				$(shell find numbers -name '*.c')			\
				$(shell find error_handling -name '*.c')	\
				$(shell find display_fns -name '*.c')

OBJS        := $(SRCS:%.c=%.o)

CC          := gcc
CFLAGS      := -W -Wall -Wextra
CPPFLAGS    := -I./

MAKEFLAGS   += --silent --no-print-directory

all : $(MAIN)

$(MAIN) : $(OBJS)
	ar rcs $(MAIN) $(OBJS)
	cp libmy.a ../
	cp my.h ../../include/my.h
	echo "\033[36mLINKED \033[32m$(OBJS)\033[0m"
	echo "\033[36mCREATED \033[32m$(MAIN)\033[0m"

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo "\033[36mCOMPILED \033[32m$<\033[0m"

clean :
	$(RM) $(OBJS) $(SRC_PATH)*~
	echo "\033[36mDELETED \033[32m$(OBJS)\033[0m"

fclean : clean
	$(RM) $(MAIN)
	$(RM) ../$(MAIN)
	echo "\033[36mDELETED \033[32m$(MAIN)\033[0m"

re : fclean all

.PHONY: all clean fclean re
.SILENT:
