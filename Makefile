# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:29:08 by bmangin           #+#    #+#              #
#    Updated: 2022/03/14 23:13:46 by bmangin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ********************************   PATH   ********************************** #

override PATH_S		:= srcs
override PATH_ST	:= stack
override PATH_SE	:= set
override PATH_V		:= vector
override PATH_M		:= map
override PATH_T		:= tools
override PATH_I		:= includes
override PATH_B		:= .bin

override VPATH		:= ${addprefix ${PATH_S}/, ${PATH_ST}} \
					${addprefix ${PATH_S}/, ${PATH_SE}} \
					${addprefix ${PATH_S}/, ${PATH_V}} \
					${addprefix ${PATH_S}/, ${PATH_M}} \
					${addprefix ${PATH_S}/, ${PATH_T}} \
					${PATH_S} ${PATH_I}


# *******************************   FILES   ********************************** #

FILES_S				:= main.cpp
FILES_ST			:= stack.cpp
FILES_SE			:= set.cpp
FILES_V				:= vector.cpp
FILES_M				:= map.cpp
FILES_T				:= tools.cpp

FILES				= ${addprefix ${PATH_ST}/, ${FILES_ST}} \
					${addprefix ${PATH_SE}/, ${FILES_SE}} \
					${addprefix ${PATH_V}/, ${FILES_V}} \
					${addprefix ${PATH_M}/, ${FILES_M}} \
					${addprefix ${PATH_T}/, ${FILES_T}} \
					${FILES_S}

SRCS				:= ${addprefix ${PATH_S}/, ${FILES}}
OBJS				:= ${SRCS:.cpp=.o}


# ******************************   INCLUDE   ********************************* #

HEADERS				:= stack.hpp set.hpp vector.hpp map.hpp tools.hpp
INCS				:= ${addprefix ${PATH_I}/, ${HEADERS}}


# *****************************   COMMANDES   ******************************** #

CC					:= clang++
FLAGS				:= -Werror -Wall -Wextra -std=c++98
CCF					:= ${CC} ${FLAGS} -I${PATH_I}

RM					:= rm -rf

# *****************************   MAKE SHIT   ******************************** #

all:	crea_b
	echo ${CCF}
		
crea_b:
	${shell mkdir -p ${PATH_B}}	

clean:
	${RM} ${PATH_B}

fclean: clean

re: fclean all

.PHONY: all clean fclean re

