# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 14:31:35 by lleveque          #+#    #+#              #
#    Updated: 2022/09/29 16:41:50 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.cpp

OBJS = ${SRCS:.cpp=.o}

DEPS = ${SRCS:.cpp=.d}

NAME = ft_containers

CC = c++

CFLAG = -pedantic -Wall -Wextra -Werror -std=c++98 -MMD

MV = mv -f

RM = rm -rf

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAG} ${OBJS} -o ${NAME}

%.o : %.cpp
			${CC} ${CFLAG} -c $< -o $@

-include ${DEPS}

clean:
			${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
