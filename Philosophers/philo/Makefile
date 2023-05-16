# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 12:22:10 by sanan             #+#    #+#              #
#    Updated: 2023/03/06 08:11:37 by sanan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =\
frees.c\
init.c\
init_2.c\
parse.c\
philo.c\
utils_fork.c\
utils_print.c\
utils_dead.c\
utils_dining.c\
utils_time.c

OBJS = $(SRCS:.c=.o)

CC = cc

WFLAGS = -Wall -Wextra -Werror

all : $(NAME)
	@$(ECHO) $(PURPLE) "🐶 philo : I'm Ready!" $(RESET)

$(NAME) : $(OBJS) $(LIB_FT)
	@$(ECHO) $(CYAN) 🐶 assembling $(GREEN) $@
	@$(CC) $(WFLAGS) $(SRCS) -o $(NAME)

%.o : %.c
	@$(ECHO) $(BLUE) 🐶 compiling $(GREEN) $<
	@$(CC) $(WFLAGS) -c $< -o $@


clean :
	@rm -rf $(OBJS)
	@echo $(RED) "	   🐶 cleaned object files!" $(RESET)

fclean : clean
	@rm -rf $(NAME)
	@echo $(RED) "	   🐶 cleaned archive, target files!" $(RESET)

re :
	@make fclean
	@make all

RESET	=	"\x1b[0m"
GREY	=	"\x1b[30m"
RED		=	"\x1b[31m"
GREEN	=	"\x1b[32m"
YELLOW	=	"\x1b[33m"
BLUE	=	"\x1b[34m"
PURPLE	=	"\x1b[35m"
CYAN	=	"\x1b[36m"
WHITE	=	"\x1b[37m"

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo $(YELLOW) "`expr " [ \`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`% ]" $(RESET)
endif

.PHONY : all clean fclean re