/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:27:45 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:41:35 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_a_above(t_deque *a, t_deque *b, t_deque *cmd)
{
	int	*ranks;
	int	idx_one;
	int	count_ra;

	ranks = get_ranks(a, 4);
	idx_one = 0;
	count_ra = 0;
	while (ranks[idx_one])
	{
		if (ranks[idx_one] == 1)
			break ;
		idx_one++;
	}
	while (--idx_one >= 0)
	{
		ra(a, cmd);
		count_ra++;
	}
	pb(a, b, cmd);
	while (--count_ra >= 0)
		rra(a, cmd);
	sort_three_below_a_above(a, cmd);
	pa(a, b, cmd);
	free_strictly(&ranks);
}

void	sort_four_b_above(t_deque *a, t_deque *b, t_deque *cmd)
{
	int	*ranks;
	int	idx_four;
	int	count_rb;

	ranks = get_ranks(b, 4);
	idx_four = 0;
	count_rb = 0;
	while (ranks[idx_four])
	{
		if (ranks[idx_four] == 4)
			break ;
		idx_four++;
	}
	while (--idx_four >= 0)
	{
		rb(b, cmd, 0);
		count_rb++;
	}
	pa(a, b, cmd);
	while (--count_rb >= 0)
		rrb(b, cmd, 0);
	sort_three_below_b_above(b, cmd);
	pb(a, b, cmd);
	free_strictly(&ranks);
}

void	sort_below_five_a(t_deque *a, t_deque *b, t_deque *cmd, int counts)
{
	if (counts == 5)
	{
		if (a->size == 5)
			sort_five_a(a, b, cmd);
		else
			sort_five_a_above(a, b, cmd);
	}
	if (counts == 4)
	{
		if (a->size == 4)
			sort_four_a(a, b, cmd);
		else
			sort_four_a_above(a, b, cmd);
	}
	if (counts <= 3)
	{
		if (a->size <= 3)
			sort_three_below_a(a, cmd, counts);
		else
			sort_three_below_a_above(a, cmd);
	}
}

void	sort_below_five_b(t_deque *a, t_deque *b, t_deque *cmd, int counts)
{
	if (counts == 5)
	{
		if (b->size == 5)
			sort_five_b(a, b, cmd);
		else
			sort_five_b_above(a, b, cmd);
	}
	if (counts == 4)
	{
		if (b->size == 4)
			sort_four_b(a, b, cmd);
		else
			sort_four_b_above(a, b, cmd);
	}
	if (counts <= 3)
	{
		if (b->size <= 3)
			sort_three_below_b(b, cmd, counts);
		else
			sort_three_below_b_above(b, cmd);
	}
}
