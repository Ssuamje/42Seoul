/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:14:44 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:42:55 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_ranks(t_deque *deq, int *ranks, int counts)
{
	t_dlist	*check_tmp;
	t_dlist	*find_tmp;
	int		idx;
	int		jdx;

	check_tmp = deq->front;
	find_tmp = deq->front->next;
	idx = -1;
	while (++idx < counts)
	{
		jdx = -1;
		find_tmp = deq->front;
		while (++jdx < counts)
		{
			if (check_tmp->content > find_tmp->content)
				(ranks[idx])++;
			find_tmp = find_tmp->next;
		}
		check_tmp = check_tmp->next;
	}
	return (ranks);
}

int	*get_ranks(t_deque *deq, int counts)
{
	int		*ranks;
	int		idx;

	if (deq->size == 0)
		return (NULL);
	ranks = malloc(sizeof(int) * counts);
	if (ranks == NULL)
		error_exit(ERR_ALLOC);
	idx = 0;
	while (idx < counts)
		ranks[idx++] = 1;
	return (make_ranks(deq, ranks, counts));
}

void	set_ranks(t_deque *deq, int *ranks)
{
	t_dlist	*tmp;
	int		idx;

	tmp = deq->front;
	idx = 0;
	while (idx < deq->size)
	{
		tmp->content = ranks[idx++];
		tmp = tmp->next;
	}
}

void	set_pivots(t_deque *deq, t_sort *info)
{
	int		rank_large;
	int		rank_small;
	t_dlist	*tmp;
	int		idx;
	int		*ranks;

	rank_large = ((info->sort_range / 3) * 2) + 1;
	if ((info->sort_range / 3) % 2 == 0)
		rank_small = (info->sort_range / 3) + 1;
	else
		rank_small = (info->sort_range / 3);
	tmp = deq->front;
	idx = 0;
	ranks = get_ranks(deq, info->sort_range);
	while (idx < info->sort_range)
	{
		if (ranks[idx] == rank_large)
			info->pivot_large = tmp->content;
		if (ranks[idx] == rank_small)
			info->pivot_small = tmp->content;
		tmp = tmp->next;
		idx++;
	}
	free_strictly(&ranks);
}

void	place_chunks_in_order(t_sort info, t_deque *a, t_deque *b, t_deque *cmd)
{
	if (info.count_ra == a->size)
		info.count_ra = 0;
	if (info.count_rb == b->size)
		info.count_rb = 0;
	while (info.count_ra && info.count_rb)
	{
		rrr(a, b, cmd);
		(info.count_ra)--;
		(info.count_rb)--;
	}
	while (info.count_ra)
	{
		rra(a, cmd);
		(info.count_ra)--;
	}
	while (info.count_rb)
	{
		rrb(b, cmd, 0);
		(info.count_rb)--;
	}
}
