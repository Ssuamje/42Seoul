# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 21:10:36 by sanan             #+#    #+#              #
#    Updated: 2022/12/28 21:50:19 by sanan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINITALK = MINITALK
NAME = server
NAME2 = client

DIR_UTILS = ./utils

SRCS_SERVER = \
server.c \
$(DIR_UTILS)/ft_putnbr_fd.c \
$(DIR_UTILS)/ft_putstr_fd.c \
$(DIR_UTILS)/ft_utils.c

SRCS_CLIENT = \
client.c \
$(DIR_UTILS)/ft_atoi.c \
$(DIR_UTILS)/ft_putnbr_fd.c \
$(DIR_UTILS)/ft_putstr_fd.c \
$(DIR_UTILS)/ft_utils.c

SRCS_SERVER_BONUS = \
server_bonus.c \
$(DIR_UTILS)/ft_putnbr_fd_bonus.c \
$(DIR_UTILS)/ft_putstr_fd_bonus.c \
$(DIR_UTILS)/ft_utils_bonus.c

SRCS_CLIENT_BONUS = \
client_bonus.c \
$(DIR_UTILS)/ft_atoi_bonus.c \
$(DIR_UTILS)/ft_putnbr_fd_bonus.c \
$(DIR_UTILS)/ft_putstr_fd_bonus.c \
$(DIR_UTILS)/ft_utils_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

CC = cc

WFLAGS = -Wall -Werror -Wextra

ifdef BONUS
	OBJS_SERVER_CHOSEN = $(OBJS_SERVER_BONUS)
	OBJS_CLIENT_CHOSEN = $(OBJS_CLIENT_BONUS)
else
	OBJS_SERVER_CHOSEN	= $(OBJS_SERVER)
	OBJS_CLIENT_CHOSEN	= $(OBJS_CLIENT)
endif

all : $(NAME) $(NAME2)

$(NAME) : $(OBJS_SERVER_CHOSEN)
	$(CC) $(WFLAGS) $(OBJS_SERVER_CHOSEN) -o $@

$(NAME2) : $(OBJS_CLIENT_CHOSEN)
	$(CC) $(WFLAGS) $(OBJS_CLIENT_CHOSEN) -o $@

%.o: %.c
	$(CC) -c $(WFLAG) $< -o $@
	
clean :
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME2)

bonus :
	make BONUS=1 all

re : fclean all

.PHONY : all clean fclean bonus re
