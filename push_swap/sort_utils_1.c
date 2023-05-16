/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:56:16 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:41:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strictly(int **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	sort_three_below_a(t_deque *a, t_deque *cmd, int counts)
{
	int	*ranks;

	ranks = get_ranks(a, counts);
	if (a->size == 2 && a->front->next->content < a->front->content)
		sa(a, cmd);
	if (a->size >= 3)
	{
		if (ranks[0] == 1 && ranks[1] == 3)
		{
			rra(a, cmd);
			sa(a, cmd);
		}
		if (ranks[0] == 2 && ranks[1] == 1)
			sa(a, cmd);
		if (ranks[0] == 2 && ranks[1] == 3)
			rra(a, cmd);
		if (ranks[0] == 3 && ranks[1] == 1)
			ra(a, cmd);
		if (ranks[0] == 3 && ranks[1] == 2)
		{
			ra(a, cmd);
			sa(a, cmd);
		}
	}
	free_strictly(&ranks);
}

void	sort_three_below_b(t_deque *b, t_deque *cmd, int counts)
{
	int	*ranks;

	ranks = get_ranks(b, counts);
	if (b->size == 2 && b->front->next->content > b->front->content)
		sb(b, cmd);
	if (b->size >= 3)
	{
		if (ranks[0] == 1 && ranks[1] == 2)
		{
			rb(b, cmd, 0);
			sb(b, cmd);
		}
		if (ranks[0] == 1 && ranks[1] == 3)
			rb(b, cmd, 0);
		if (ranks[0] == 2 && ranks[1] == 1)
			rrb(b, cmd, 0);
		if (ranks[0] == 2 && ranks[1] == 3)
			sb(b, cmd);
		if (ranks[0] == 3 && ranks[1] == 1)
		{
			rrb(b, cmd, 0);
			sb(b, cmd);
		}
	}
	free_strictly(&ranks);
}

void	push_four_b_to_a(t_deque *a, t_deque *b, t_deque *cmd)
{
	int	*ranks;
	int	idx;

	ranks = get_ranks(b, 4);
	idx = 0;
	while (ranks[idx])
	{
		if (ranks[idx] == 4)
			break ;
		idx++;
	}
	if (idx == 1)
		rb(b, cmd, 0);
	if (idx == 2)
	{
		rrb(b, cmd, 0);
		rrb(b, cmd, 0);
	}
	if (idx == 3)
		rrb(b, cmd, 0);
	pa(a, b, cmd);
	free_strictly(&ranks);
}

void	push_one_or_two_a_to_b(t_deque *a, t_deque *b, t_deque *cmd, int num)
{
	int	*ranks;
	int	idx;

	ranks = get_ranks(a, 4);
	idx = 0;
	while (ranks[idx])
	{
		if (ranks[idx] == num)
			break ;
		idx++;
	}
	if (idx == 1)
		ra(a, cmd);
	if (idx == 2)
	{
		ra(a, cmd);
		ra(a, cmd);
	}
	if (idx == 3)
		rra(a, cmd);
	pb(a, b, cmd);
	free_strictly(&ranks);
}
