/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:43:52 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:41:07 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_small(t_deque *a, t_deque *b, t_deque *cmd, t_sort *info)
{
	if (info->flag_ra == 1)
	{
		rr(a, b, cmd);
		info->flag_ra = 0;
	}
	else
		rb(b, cmd, 0);
	(info->count_rb)++;
}

void	divide_large_medium(t_deque *a, t_deque *b, t_deque *cmd, t_sort *info)
{
	pa(a, b, cmd);
	(info->count_pa)++;
	if ((a->front->content < info->pivot_large) && a->size > 1)
	{
		if (b->size > 1 && (b->front->content < info->pivot_small) && \
			info->idx + 1 != info->sort_range)
			info->flag_ra = 1;
		else
			if (a->size > 1)
				ra(a, cmd);
		info->count_ra++;
	}
}

void	quick_sort_b(int sort_range, t_deque *a, t_deque *b, t_deque *cmd)
{
	t_sort	info;

	init_sort(&info, sort_range);
	if (sort_range <= 5)
	{
		sort_below_five_b(a, b, cmd, sort_range);
		pa_times(a, b, cmd, sort_range);
		return ;
	}
	set_pivots(b, &info);
	while (info.idx < sort_range)
	{
		if ((b->front->content < info.pivot_small) && b->size > 1)
			divide_small(a, b, cmd, &info);
		else
			divide_large_medium(a, b, cmd, &info);
		info.idx++;
	}
	quick_sort_a((info.count_pa - info.count_ra), a, b, cmd);
	place_chunks_in_order(info, a, b, cmd);
	quick_sort_a(info.count_ra, a, b, cmd);
	quick_sort_b(info.count_rb, a, b, cmd);
}
