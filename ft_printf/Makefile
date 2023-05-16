# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:39:44 by sanan             #+#    #+#              #
#    Updated: 2022/11/30 10:15:28 by sanan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
ft_printf_put.c\
ft_printf_put_convert.c\
putnbr_base.c\
putnbr_decimal.c

OBJS = ${SRCS:.c=.o}

CC = cc

WFLAG = -Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJS}
	ar -rcus $@ $^

%.o : %.c
	${CC} -c ${WFLAG} $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re