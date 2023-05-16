/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:05:04 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 13:24:41 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "queue.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <limits.h>

typedef struct s_sort{
	int	count_ra;
	int	count_rb;
	int	count_pa;
	int	count_pb;
	int	flag_ra;
	int	flag_rb;
	int	pivot_large;
	int	pivot_small;
	int	sort_range;
	int	idx;
}	t_sort;

typedef struct s_idx{
	int	idx_iter;
	int	idx_five;
	int	idx_four;
	int	count_ra;
	int	count_rb;
}	t_idx;

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
};

void	error_exit(int error_code);
void	write_error(char *message);

char	*is_split_ok(char *chunk);
void	free_split(char ***splitted);
int		ft_pssw_atoi(char *str);
void	check_value_duplicated(int value_to_put, t_deque *deq);
void	check_and_push(char *arg, t_deque *deq);
int		is_str_only_white_spaces(char *str);
void	check_av_str(char *av_str);
int		check_is_sorted(t_deque *deq);
t_deque	*set_deque(int ac, char **av);

void	init_sort(t_sort *info, int sort_range);
void	quick_sort_a(int counts, t_deque *a, t_deque *b, t_deque *cmd);
void	quick_sort_b(int counts, t_deque *a, t_deque *b, t_deque *cmd);
int		*get_ranks(t_deque *deq, int counts);
void	set_ranks(t_deque *deq, int *ranks);
void	set_pivots(t_deque *deq, t_sort *info);

void	init_idx(t_idx *info);
void	sort_three_below_a_above(t_deque *a, t_deque *cmd);
void	sort_three_below_b_above(t_deque *b, t_deque *cmd);
void	sort_three_below_a(t_deque *a, t_deque *cmd, int counts);
void	sort_three_below_b(t_deque *b, t_deque *cmd, int counts);
void	sort_below_five_a(t_deque *a, t_deque *b, t_deque *cmd, int counts);
void	sort_below_five_b(t_deque *a, t_deque *b, t_deque *cmd, int counts);
void	sort_five_a_above(t_deque *a, t_deque *b, t_deque *cmd);
void	sort_five_b_above(t_deque *a, t_deque *b, t_deque *cmd);
void	sort_five_a(t_deque *a, t_deque *b, t_deque *cmd);
void	sort_five_b(t_deque *a, t_deque *b, t_deque *cmd);
void	sort_four_a(t_deque *a, t_deque *b, t_deque *cmd);
void	sort_four_b(t_deque *a, t_deque *b, t_deque *cmd);
void	push_one_or_two_a_to_b(t_deque *a, t_deque *b, t_deque *cmd, int num);
void	push_one_a_to_b_2(t_deque *a, t_deque *b, t_deque *cmd);
void	push_five_four_a_to_b_above(t_deque *a, t_deque *b, t_deque *cmd);
void	push_five_four_b_to_a_above(t_deque *a, t_deque *b, t_deque *cmd);
void	push_four_b_to_a(t_deque *a, t_deque *b, t_deque *cmd);
void	push_five_b_to_a(t_deque *a, t_deque *b, t_deque *cmd);
void	pa_times(t_deque *a, t_deque *b, t_deque *cmd, int times);
void	pb_times(t_deque *a, t_deque *b, t_deque *cmd, int times);
void	free_strictly(int **ptr);
void	place_chunks_in_order(t_sort info, \
							t_deque *a, t_deque *b, t_deque *cmd);

void	print_cmd(t_deque *cmd);
void	optimize_cmd(t_deque *cmd, t_dlist *node);
int		optimize_concurrent_cmd(t_deque *cmd, t_dlist **node);
int		optimize_meaningless_cmd(t_deque *cmd, t_dlist **node);
int		optimize_meaningess_push(t_deque *cmd, t_dlist **node);
int		optimize_meaningless_rotate(t_deque *cmd, t_dlist **node);
int		optimize_meaningless_rotate_2(t_deque *cmd, t_dlist **node);
int		optimize_meaningless_swap(t_deque *cmd, t_dlist **node);
int		optimize_meaningless_swap_2(t_deque *cmd, t_dlist **node);
int		optimize_concurrent_rrotate(t_deque *cmd, t_dlist **node);
int		optimize_meaningless_rrotate_2(t_deque *cmd, t_dlist **node);
int		optimize_concurrent_rotate(t_deque *cmd, t_dlist **node);
int		optimize_concurrent_swap(t_deque *cmd, t_dlist **node);
int		optimize_rr_rrr(t_deque *cmd, t_dlist **node);

#endif