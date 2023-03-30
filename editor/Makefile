##
## EPITECH PROJECT, 2023
## myrpg
## File description:
## Makefile
##

TARGET      := editor

DIRS		:= src
SRCS        := main.c

OBJS		:= $(SRCS:.c=.o)

ALL_OBJS	:= $(OBJS)

rwildcard	=  $(foreach d,$(wildcard $(addsuffix *,$(1))),$(call rwildcard,\
$(d)/,$(2))$(filter $(subst *,%,$(2)),$(d)))

default: all

$(TARGET) : build-subdirs $(OBJS) find-all-objs
	$(CC) -o $(TARGET) $(ALL_OBJS) $(LDFLAGS) $(LDLIBS)
	echo "\033[36mLINKED \033[32m$(ALL_OBJS)\033[0m"
	echo "\033[36mCREATED \033[32m$(TARGET)\033[0m"

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean: clean-subdirs
	$(RM) $(OBJS) $(SRC_PATH)*~
	echo "\033[36mDELETED \033[32m$(OBJS)\033[0m"

.PHONY: fclean
fclean: clean
	$(RM) $(TARGET)
	echo "\033[36mDELETED \033[32m$(TARGET)\033[0m"

.PHONY: re
re: fclean all

.PHONY: debug
debug:
	$(MAKE) CFLAGS="-g3 -ggdb" re

.PHONY: build-subdirs
find-all-objs:
	$(eval ALL_OBJS += $(call rwildcard,$(DIRS),*.o))

.SILENT:

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
export PROJECT_PATH := $(patsubst %/,%,$(dir $(mkfile_path)))
export MAKE_INCLUDE=$(PROJECT_PATH)/config/make.global
export SUB_MAKE_INCLUDE=$(PROJECT_PATH)/config/submake.global
include $(MAKE_INCLUDE)
