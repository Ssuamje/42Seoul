# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 19:19:38 by sanan             #+#    #+#              #
#    Updated: 2022/12/26 14:53:24 by sanan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

GNL_DIR = ./get_next_line

SRCS = \
	$(GNL_DIR)/get_next_line_utils.c \
	$(GNL_DIR)/get_next_line.c \
	check_map_utils1.c \
	check_map_utils2.c \
	check_map_utils3.c \
	check_map.c \
	check_path.c \
	error.c \
	game_utils.c \
	get_map.c \
	main.c

OBJS = $(SRCS:.c=.o)

CC = cc

WFLAGS = -Wall -Wextra -Werror

FRAMEWORKS = -framework OpenGl -framework AppKit

LIB_MLX = ./MLX/minilibx_opengl/libmlx.a

LIB_PRINTF = ./ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_MLX) $(LIB_PRINTF)
	$(CC) $(WFLAGS) $(SRCS) $(LIB_MLX) $(LIB_PRINTF) \
	$(FRAMEWORKS) -o $(NAME)

%.o : %.c
	$(CC) $(WFLAGS) -Imlx -c $< -o $@

$(LIB_MLX) :
	make -C $(dir $(LIB_MLX))

$(LIB_PRINTF) :
	make -C $(dir $(LIB_PRINTF))

clean :
	make -C $(dir $(LIB_MLX)) clean
	make -C $(dir $(LIB_PRINTF)) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(dir $(LIB_PRINTF)) fclean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re