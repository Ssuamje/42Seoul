/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:09:13 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:43:12 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_four_below(t_deque *a, t_deque *b, t_deque *cmd, t_idx info)
{
	while (--info.idx_four >= 0)
	{
		rb(b, cmd, 0);
		info.count_rb++;
	}
	pa(a, b, cmd);
	info.idx_five = info.count_rb - info.idx_five;
	while (--info.count_rb >= 0)
	{
		rrb(b, cmd, 0);
		if (info.count_rb == info.idx_five)
			pa(a, b, cmd);
	}
}

void	push_four_above(t_deque *a, t_deque *b, t_deque *cmd, t_idx info)
{
	while (--info.idx_four >= 0)
	{
		rb(b, cmd, 0);
		info.count_rb++;
	}
	pa(a, b, cmd);
	info.idx_five -= info.count_rb;
	while (info.idx_five-- >= 0)
	{
		rb(a, cmd, 0);
		info.count_rb++;
	}
	pa(a, b, cmd);
	while (--info.count_rb >= 0)
		rrb(b, cmd, 0);
}

void	push_five_four_b_to_a_above(t_deque *a, t_deque *b, t_deque *cmd)
{
	int		*ranks;
	t_idx	info;

	ranks = get_ranks(b, 5);
	init_idx(&info);
	info.idx_iter = -1;
	while (ranks[++info.idx_iter])
	{
		if (ranks[info.idx_iter] == 4)
			info.idx_four = info.idx_iter;
		if (ranks[info.idx_iter] == 5)
			info.idx_five = info.idx_iter;
	}
	if (info.idx_five < info.idx_four)
		push_four_below(a, b, cmd, info);
	else
		push_four_above(a, b, cmd, info);
	free_strictly(&ranks);
}
