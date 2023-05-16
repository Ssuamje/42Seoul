/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:05:04 by sanan             #+#    #+#             */
/*   Updated: 2023/01/06 11:05:29 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# include "./gnl_bonus/get_next_line_bonus.h"
# include "queue_bonus.h"
# include <unistd.h>
# include <limits.h>
# define RED      "\x1b[31m"
# define GREEN    "\x1b[32m"
# define YELLOW   "\x1b[33m"
# define BLUE     "\x1b[34m"
# define MAGENTA  "\x1b[35m"
# define CYAN     "\x1b[36m"
# define RESET    "\x1b[0m"

enum	e_cmd{
	CMD_NOT_OPTIMIZED,
	CMD_OPTIMIZE_SUCCESS,
	CMD_SA,
	CMD_SB,
	CMD_SS,
	CMD_RA,
	CMD_RB,
	CMD_RR,
	CMD_PA,
	CMD_PB,
	CMD_RRA,
	CMD_RRB,
	CMD_RRR
};

enum	e_pasre_error_flags{
	ERR_ARGUMENT_COUNTS,
	ERR_ARGUMENT_EMPTY,
	ERR_ATOI_INVALID_SPACE,
	ERR_ATOI_OVERFLOW,
	ERR_DEQ,
	ERR_LIST,
	ERR_ALLOC,
	ERR_SPLIT_CHUNK,
	ERR_VALUE_DUPLICATED,
	ERR_CMD,
};

void	print_queue(t_deque *deq);
void	free_deque(t_deque *deq_ptr);

void	error_exit(int error_code);
void	write_error(char *message);

int		*get_ranks(t_deque *deq, int counts);
void	set_ranks(t_deque *deq, int *ranks);
void	free_strictly(int **ptr);
char	*is_split_ok(char *chunk);
void	free_split(char ***splitted);
int		ft_pssw_atoi(char *str);
void	check_value_duplicated(int value_to_put, t_deque *deq);
void	check_and_push(char *arg, t_deque *deq);
int		is_str_only_white_spaces(char *str);
void	check_av_str(char *av_str);
int		check_is_sorted(t_deque *deq);
t_deque	*set_deque(int ac, char **av);

void	check_line(char *cmd, t_deque *a, t_deque *b, t_deque *command);
void	get_cmd(t_deque *a, t_deque *b, t_deque *cmd);

#endif