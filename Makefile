# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 14:31:35 by lleveque          #+#    #+#              #
#    Updated: 2022/10/11 15:39:39 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

DEPS = ${SRCS:.cpp=.d}

NAME = ft_containers

CC = c++

CFLAG = -pedantic -Wall -Wextra -Werror -MMD -MP -std=c++98

MV = mv -f

RM = rm -rf

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAG} ${OBJS} -o ${NAME}

%.o : %.cpp
			${CC} ${CFLAG} -c $< -o $@

-include ${DEPS}

clean:
			${RM} ${OBJS} ${DEPS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
