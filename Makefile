# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinigo <jinigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 23:54:39 by jinigo            #+#    #+#              #
#    Updated: 2021/01/27 14:41:54 by jinigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c ft_isdigit.c ft_strchr.c ft_strlen.c  \
		ft_putchar_fd.c ft_putnbr_fd.c ft_putunbr_fd.c ft_putnbrx_fd.c \
		ft_putnbrp_fd.c write_c.c write_s.c write_di.c write_u.c write_x.c \
		write_p.c parse.c minus_di.c no_minus_di.c minus_p.c no_minus_p.c


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${OBJSBNS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
