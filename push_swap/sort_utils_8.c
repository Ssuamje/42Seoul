/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:08:55 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 22:09:45 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_five_above(t_deque *a, t_deque *b, t_deque *cmd, t_idx info)
{
	while (--info.idx_five >= 0)
	{
		ra(a, cmd);
		info.count_ra++;
	}
	pb(a, b, cmd);
	info.idx_four -= info.count_ra;
	while (info.idx_four-- >= 0)
	{
		ra(a, cmd);
		info.count_ra++;
	}
	pb(a, b, cmd);
	while (--info.count_ra >= 0)
		rra(a, cmd);
}

void	push_five_below(t_deque *a, t_deque *b, t_deque *cmd, t_idx info)
{
	while (--info.idx_five >= 0)
	{
		ra(a, cmd);
		info.count_ra++;
	}
	pb(a, b, cmd);
	info.idx_four = info.count_ra - info.idx_four;
	while (--info.count_ra >= 0)
	{
		rra(a, cmd);
		if (info.count_ra == info.idx_four)
			pb(a, b, cmd);
	}
}

void	push_five_four_a_to_b_above(t_deque *a, t_deque *b, t_deque *cmd)
{
	int		*ranks;
	t_idx	info;

	init_idx(&info);
	ranks = get_ranks(a, 5);
	info.count_ra = 0;
	info.idx_iter = -1;
	while (ranks[++info.idx_iter])
	{
		if (ranks[info.idx_iter] == 4)
			info.idx_four = info.idx_iter;
		if (ranks[info.idx_iter] == 5)
			info.idx_five = info.idx_iter;
	}
	if (info.idx_five < info.idx_four)
		push_five_above(a, b, cmd, info);
	else
		push_five_below(a, b, cmd, info);
	free_strictly(&ranks);
}
