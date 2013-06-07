##
## Makefile for 106bombyx in /home/benzah_m//106bombyx
## 
## Made by marc benzahra
## Login   <benzah_m@epitech.net>
## 
## Started on  Mon Feb 11 11:56:57 2013 marc benzahra
## Last update Thu Mar 28 15:50:13 2013 marc benzahra
##

SRC	=		109titrage.c	\
		coregnl.c	\

SRC_SDL	=	109titrage_sdl.c	\

OBJ	=		$(SRC:.c=.o)
OBJ_SDL	=	$(SRC_SDL:.c=.o)

RM	=	rm -f

CC	=	cc

NAME	=	109titrage

LIB	=		-lm -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11
LIB_SDL	=	-lm -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lSDL -lSDL_mixer

RESET=		\033[0m
BIG=		\033[1;01m
UNDERLINE=	\033[1;04m
BLINGBLING=	\033[1;05m
VIDEO=		\033[1;07m
C_BLACK=	\033[1;30m
C_RED=		\033[1;31m
C_GREEN=	\033[1;32m
C_ORANGE=	\033[1;33m
C_BLUE=		\033[1;34m
C_PINK=		\033[1;35m
C_GAYBLUE=	\033[1;36m
C_WHITE=	\033[1;37m
B_BLACK=	\033[1;40m
B_RED=		\033[1;41m
B_GREEN=	\033[1;42m
B_ORANGE=	\033[1;43m
B_BLUE=		\033[1;44m
B_PINK=		\033[1;45m
B_GAYBLUE=	\033[1;46m
B_WHITE=	\033[1;47m

all:	evo $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

sdl:		gw2 $(OBJ_SDL)
	$(CC) -o $(NAME) $(OBJ_SDL) $(LIB_SDL)

clean:
	$(RM) $(OBJ) $(OBJ_SDL)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

osama:
	@clear
	@cat matrix/scene01
	@sleep 0.1
	@clear
	@cat matrix/scene02
	@sleep 0.1
	@clear
	@cat matrix/scene03
	@sleep 0.1
	@clear
	@cat matrix/scene04
	@sleep 0.1
	@clear
	@cat matrix/scene05
	@sleep 0.1
	@clear
	@cat matrix/scene06
	@sleep 0.1
	@clear
	@cat matrix/scene07
	@sleep 0.1
	@clear
	@cat matrix/scene08
	@sleep 0.1
	@clear
	@cat matrix/scene09
	@sleep 0.1
	@clear
	@cat matrix/scene10
	@sleep 0.1
	@clear
	@cat matrix/scene11
	@sleep 0.1
	@clear
	@cat matrix/scene12
	@sleep 0.1
	@clear
	@cat matrix/scene13
	@sleep 0.1
	@clear
	@cat matrix/scene14
	@sleep 0.1
	@clear
	@cat matrix/scene15
	@sleep 0.1
	@clear
	@cat matrix/scene16
	@sleep 0.1
	@clear
	@cat matrix/scene17
	@sleep 0.1
	@clear
	@cat matrix/scene18
	@sleep 0.1
	@clear
	@cat matrix/scene19
	@sleep 0.1
	@echo -e "$(RESET)"

gw2:
	@clear
	@echo -e "$(C_RED)"
	@echo -e "$(BLINGBLING)"
	@cat pokedex/guild_wars_2
	@echo -e "$(RESET)"

evo:
	@clear
	@echo -e "$(C_RED)"
	@echo -e "$(BLINGBLING)"
	@cat pokedex/004charmander
	@sleep 1
	@clear
	@echo -e "$(C_RED)"
	@echo -e "$(BLINGBLING)"
	@cat pokedex/005charmeleon
	@sleep 1
	@clear
	@echo -e "$(C_RED)"
	@echo -e "$(BLINGBLING)"
	@cat pokedex/006charizard
	@sleep 1
	@echo -e "$(RESET)"
