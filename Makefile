# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:29:08 by bmangin           #+#    #+#              #
#    Updated: 2022/05/18 00:39:29 by bmangin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME				:= ft_containers

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
					${PATH_S}


# *******************************   FILES   ********************************** #

FILES_S				:= main
FILES_T				:= iterator iterators_traits reverse_iterator
FILES				:= ${addprefix ${PATH_ST}/, ${PATH_ST}} \
					${addprefix ${PATH_SE}/, ${PATH_SE}} \
					${addprefix ${PATH_V}/, ${PATH_V}} \
					${addprefix ${PATH_M}/, ${PATH_M}} \
					${addprefix ${PATH_T}/, ${FILES_T}} 

ALL_FILES			= ${FILES} ${FILES_S}

SRCS				:= ${addprefix ${PATH_S}/, ${addsuffix .cpp, ${FILES}}}
OBJS				:= ${SRCS:.cpp=.o}

# ******************************   INCLUDE   ********************************* #

INCS				:= ${addprefix ${PATH_I}/, ${addsuffix .hpp, ${FILES}}}


# *****************************   COMMANDES   ******************************** #

CC					:= c++
FLAGS				:= -Werror -Wall -Wextra -std=c++98
CCF					:= ${CC} ${FLAGS} -I ${PATH_I}/
# CCF					:= ${CC} ${FLAGS} -I${INCS}

RM					:= rm -rf

# *****************************   MAKE SHIT   ******************************** #

# all:	crea_b ${NAME}
all:	see_more crea_b ${NAME}
	
see_more:
	echo ${CCF} ${FILES}"\033[0m"
	echo "srcs:"
	echo ${SRCS}
	echo "includes:"
	echo ${INCS}

${PATH_B}/%.o: %.cpp ${HEADER}
	$(CCF) -o $@ -c $<

${NAME}: ${OBJS}
	${CCF} -o ${NAME} ${OBJS}

crea_b:
	${shell mkdir -p ${PATH_B}}	


clean:
	${RM} ${PATH_B}

fclean: clean

re: fclean all

.PHONY: all clean fclean re

