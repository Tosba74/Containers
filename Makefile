# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:29:08 by bmangin           #+#    #+#              #
#    Updated: 2022/06/11 03:55:54 by bmangin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME				:= ft_containers

# ********************************   PATH   ********************************** #

override PATH_S		:= srcs
override PATH_ST	:= stack
override PATH_SE	:= set
override PATH_V		:= vector
override PATH_M		:= map
override PATH_TOOL	:= tools
override PATH_TEST	:= test
override PATH_I		:= includes
override PATH_B		:= .bin

override VPATH		:= ${addprefix ${PATH_S}/, ${PATH_ST}} \
					${addprefix ${PATH_S}/, ${PATH_SE}} \
					${addprefix ${PATH_S}/, ${PATH_V}} \
					${addprefix ${PATH_S}/, ${PATH_M}} \
					${addprefix ${PATH_S}/, ${PATH_TOOL}} \
					${PATH_S}
# ${addprefix ${PATH_S}/, ${PATH_TEST}}


# *******************************   FILES   ********************************** #

FILES_S				:= main
FILES_TOOL			:= iterator reverse_iterator enable_if is_integral 
#FILES_TOOL			:= iterator enable_if is_integral iterator_traits reverse_iterator enable_if is_integral
# FILES_TEST			:= 
FILES				:= ${addprefix ${PATH_ST}/, ${PATH_ST}} \
					${addprefix ${PATH_SE}/, ${PATH_SE}} \
					${addprefix ${PATH_V}/, ${PATH_V}} \
					${addprefix ${PATH_M}/, ${PATH_M}} \
					${addprefix ${PATH_TOOL}/, ${FILES_TOOL}} 
# ${addprefix ${PATH_TEST/, ${FILES_TEST}} 

ALL_FILES			= ${FILES} ${FILES_S}

SRCS				:= ${addprefix ${PATH_S}/, ${addsuffix .cpp, ${ALL_FILES}}}
OBJS				:= ${addprefix ${PATH_B}/, ${notdir ${SRCS:.cpp=.o}}}

# ******************************   INCLUDE   ********************************* #

# INCS				:= ${addsuffix .hpp, ${FILES}}
# INC					:= ${addprefix ${PATH_I}/, ${INCS}}
INCS				:= ${addprefix ${PATH_I}/, ${addsuffix .hpp, ${FILES}}}


# *****************************   COMMANDES   ******************************** #

CC					:= c++
FLAGS				:= -Werror -Wall -Wextra# -std=c++98
INC					:= -I${PATH_I}
CCF					:= ${CC} ${FLAGS} ${INC}
FS					:= -g3 -fsanitize=address 
CCFS				:= ${CC} ${FLAGS} ${INC} ${FS}

RM					:= rm -rf

# *****************************   MAKE SHIT   ******************************** #

# all:	crea_b ${NAME}
all:	see_more crea_b ${NAME}
	
see_more:
	# echo ${CCF} ${SRCS}
	# echo "srcs:"
	# echo ${OBJS}
	# echo "includes:"
	# echo ${INCS}

crea_b:
	${shell mkdir -p ${PATH_B}}	

${NAME}: ${OBJS}
	${CCF} -o ${NAME} ${OBJS}

fs: ${OBJS}
	${CCFS} -o ${NAME} ${OBJS}
	
${PATH_B}/%.o: %.cpp ${INCS}
	${CCF} -o $@ -c $<

clean:
	${RM} ${PATH_B}

fclean: clean

seg: fclean fs

re: fclean all

.PHONY: all clean fclean re

