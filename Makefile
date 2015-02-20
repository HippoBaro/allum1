##
## Makefile for alum1 in /home/barrau_h
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Mon Feb 16 00:55:08 2015 Hippolyte Barraud
## Last update Thu Feb 19 22:33:42 2015 Hippolyte Barraud
##

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror -pedantic

CFLAGS		+= -Wno-overlength-strings -pthread -O2

NAME		= allum1

SRCPATH		= ./srcs/

MISCSPATH	= $(SRCPATH)miscs/

IAPATH		= $(SRCPATH)IA/

COREPATH	= $(SRCPATH)core/

PLAYERPATH	= $(COREPATH)Players/

GAMEPATH	= $(COREPATH)GameLogic/

MAPPATH		= $(COREPATH)Map/

SRCS		= $(SRCPATH)main.c			\
		  $(IAPATH)gauss_resolve.c		\
		  $(IAPATH)IA.c				\
		  $(IAPATH)thread.c			\
		  $(COREPATH)errors.c			\
		  $(COREPATH)list.c			\
		  $(COREPATH)new_game.c			\
		  $(COREPATH)menu.c			\
		  $(GAMEPATH)gameplay.c			\
		  $(GAMEPATH)rules.c			\
		  $(MISCSPATH)stroutput.c		\
		  $(MISCSPATH)strinput.c		\
		  $(PLAYERPATH)new_player.c		\
		  $(PLAYERPATH)player_utils.c		\
		  $(MAPPATH)map_utils.c			\
		  $(MAPPATH)map_prompt.c		\
		  $(MAPPATH)map_generator.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
