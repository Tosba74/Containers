# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 08:11:56 by bmangin           #+#    #+#              #
#    Updated: 2022/10/03 15:27:01 by bmangin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := ft_containers

# ********************************   PATH   ********************************** #


override PATH_S		:= srcs
override PATH_I		:= includes
override PATH_B		:= .bin
override PATH_V		:= vector
override PATH_ST	:= stack
override PATH_M		:= map
override PATH_IT	:= iterator
override PATH_TOOL	:= tools

override VPATH		:= ${addprefix ${PATH_S}/, ${PATH_TOOL}} \
					${addprefix ${PATH_S}/, ${PATH_IT}} \
					${addprefix ${PATH_S}/, ${PATH_ST}} \
					${addprefix ${PATH_S}/, ${PATH_V}} \
					${addprefix ${PATH_S}/, ${PATH_M}} \
					${PATH_S}
 
# ********************************	 FILES   ********************************* #

FILES_S				:= main

FILES_TOOL			:= exceptions pair nodes tools

FILES				:= ${addprefix ${PATH_TOOL}/, ${FILES_TOOL}} \
					${addprefix ${PATH_IT}/, ${PATH_IT}} \
					${addprefix ${PATH_ST}/, ${PATH_ST}} \
					${addprefix ${PATH_M}/, ${PATH_M}} \
					${addprefix ${PATH_V}/, ${PATH_V}}

ALL_FILES			:= ${FILES} ${FILES_S}

SRCS				:= ${addprefix ${PATH_S}/, ${addsuffix .cpp, ${ALL_FILES}}}
OBJS				:= ${addprefix ${PATH_B}/, ${notdir ${SRCS:.cpp=.o}}}

# ******************************   INCLUDES   ******************************** #

INCS				:= ${addprefix ${PATH_I}/, ${addsuffix .hpp, ${FILES}}}
INCL				:= ${addprefix ${PATH_I}/, ${PATH_TOOL}} \
					${addprefix ${PATH_I}/, ${PATH_IT}} \
					${addprefix ${PATH_I}/, ${PATH_M}} \
					${addprefix ${PATH_I}/, ${PATH_V}}

# ********************************   CMDS   ********************************** #

CC					:= c++
FLAGS				:= -Werror -Wall -Wextra -std=c++98
INC					:= ${addprefix -I, ${PATH_I}}
CCF					:= ${CC} ${FLAGS} ${INC}
FS					:= -g3 -fsanitize=address 
CCFS				:= ${CC} ${FLAGS} ${INC} ${FS}

RM					:= rm -rf

# ******************************   MAKE SHIT   ******************************* #

all: crea_b ${NAME}
	$(info $$var is [${PATH_B}])
	
see_var:
	@ echo ${NAME}
	@ echo contient:
	@ echo ${VPATH}
	@ echo ${SRCS}
	@ echo ${INCS}
	@ echo ${OBJS}

${NAME}: ${OBJS}
	${CCF} -o ${NAME} ${OBJS}
	
fs: ${OBJS}
	${CCFS} -o ${NAME} ${OBJS}
	
${PATH_B}/%.o: %.cpp ${INCS}
	${CCF} -o $@ -c $<
	
crea_b:
	${shell mkdir -p ${PATH_B}}	
	@echo ".bin created"
	
clean:
	${RM} ${PATH_B}
	@echo ".bin deleted"

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re