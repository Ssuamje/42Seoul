# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 07:57:03 by sanan             #+#    #+#              #
#    Updated: 2023/01/06 17:23:13 by sanan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

DIR_BONUS = ./bonus
DIR_GNL_BONUS = $(DIR_BONUS)/gnl_bonus

SRCS_PSSW = \
cmd.c \
cmd_utils_1.c \
cmd_utils_2.c \
cmd_utils_3.c \
error.c \
main.c \
parse.c \
parse_utils.c \
queue.c \
queue_utils_1.c \
queue_utils_2.c \
queue_utils_3.c \
queue_utils_4.c \
queue_utils_5.c \
sort_a.c \
sort_b.c \
sort_small.c \
sort_utils_1.c \
sort_utils_2.c \
sort_utils_3.c \
sort_utils_4.c \
sort_utils_5.c \
sort_utils_6.c \
sort_utils_7.c \
sort_utils_8.c \
sort_utils_9.c


SRCS_CHECKER = \
$(DIR_BONUS)/checker_utils_bonus.c \
$(DIR_BONUS)/cmd_bonus.c \
$(DIR_BONUS)/error_bonus.c \
$(DIR_BONUS)/main_bonus.c \
$(DIR_BONUS)/parse_bonus.c \
$(DIR_BONUS)/parse_utils_bonus.c \
$(DIR_BONUS)/print_bonus.c \
$(DIR_BONUS)/queue_bonus.c \
$(DIR_BONUS)/queue_utils_1_bonus.c \
$(DIR_BONUS)/queue_utils_2_bonus.c \
$(DIR_BONUS)/queue_utils_3_bonus.c \
$(DIR_BONUS)/queue_utils_4_bonus.c \
$(DIR_GNL_BONUS)/get_next_line_bonus.c \
$(DIR_GNL_BONUS)/get_next_line_utils_bonus.c \

OBJS_PSSW = $(SRCS_PSSW:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

LIB_FT = ./libft/libft.a

CC = cc

WFLAGS = -Wall -Werror -Wextra

all : $(NAME)

bonus : $(NAME2)

$(NAME) : $(OBJS_PSSW) $(LIB_FT)
	$(CC) $(WFLAGS) $(SRCS_PSSW) $(LIB_FT) -o $@

$(NAME2) : $(OBJS_CHECKER) $(LIB_FT)
	$(CC) $(WFLAGS) $(SRCS_CHECKER) $(LIB_FT) -o $@

$(LIB_FT) :
	make -C $(dir $(LIB_FT))

%.o: %.c
	$(CC) -c $(WFLAG) $< -o $@

clean :
	make -C $(dir $(LIB_FT)) clean
	rm -rf $(OBJS_PSSW) $(OBJS_CHECKER)

fclean : clean
	make -C $(dir $(LIB_FT)) fclean
	rm -rf $(NAME) $(NAME2)

re :
	make fclean
	make all
	make bonus

.PHONY : all clean fclean bonus re