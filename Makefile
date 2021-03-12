# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 12:14:53 by lturbang          #+#    #+#              #
#    Updated: 2020/10/07 13:45:07 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_strlen.s		\
				ft_strcpy.s		\
				ft_strcmp.s		\
				ft_write.s		\
				ft_read.s		\
				ft_strdup.s		\

OBJS		= ${SRCS:.s=.o}

NAME		= libasm.a

NA			= nasm

NA_FLAGS	= -f elf64

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.s.o:
			${NA} ${NA_FLAGS} -s $< -o ${<:.s=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

test:		all
			gcc ${CFLAGS} -no-pie main.c main2.c libasm.a -o test_libasm
			./test_libasm

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re test
