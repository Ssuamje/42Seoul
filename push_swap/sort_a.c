/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:32:00 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:40:52 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort(t_sort *info, int sort_range)
{
	info->count_pa = 0;
	info->count_pb = 0;
	info->count_ra = 0;
	info->count_rb = 0;
	info->flag_ra = 0;
	info->flag_rb = 0;
	info->pivot_large = 0;
	info->pivot_small = 0;
	info->sort_range = sort_range;
	info->idx = 0;
}

void	divide_large(t_deque *a, t_deque *b, t_deque *cmd, t_sort *info)
{
	if (info->flag_rb == 1)
	{
		rr(a, b, cmd);
		info->flag_rb = 0;
	}
	else
		ra(a, cmd);
	(info->count_ra)++;
}

void	divide_medium_small(t_deque *a, t_deque *b, t_deque *cmd, t_sort *info)
{
	pb(a, b, cmd);
	(info->count_pb)++;
	if (b->front->content >= info->pivot_small)
	{
		if (a->size > 1 && (a->front->content >= info->pivot_large) && \
			(info->idx + 1) != info->sort_range)
			info->flag_rb = 1;
		else
			if (b->size > 1)
				rb(b, cmd, 0);
		(info->count_rb)++;
	}
}

void	quick_sort_a(int sort_range, t_deque *a, t_deque *b, t_deque *cmd)
{
	t_sort	info;

	init_sort(&info, sort_range);
	if (sort_range <= 5)
		return (sort_below_five_a(a, b, cmd, sort_range));
	set_pivots(a, &info);
	info.idx = 0;
	while (info.idx < sort_range)
	{
		if ((a->front->content >= info.pivot_large) && a->size > 1)
			divide_large(a, b, cmd, &info);
		else
			divide_medium_small(a, b, cmd, &info);
		info.idx++;
	}
	place_chunks_in_order(info, a, b, cmd);
	quick_sort_a(info.count_ra, a, b, cmd);
	quick_sort_b(info.count_rb, a, b, cmd);
	quick_sort_b((info.count_pb - info.count_rb), a, b, cmd);
}
