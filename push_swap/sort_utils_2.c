/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:57:45 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:42:11 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_one_a_to_b_2(t_deque *a, t_deque *b, t_deque *cmd)
{
	int	*ranks;
	int	idx;

	ranks = get_ranks(a, 5);
	idx = -1;
	while (ranks[++idx])
		if (ranks[idx] == 1)
			break ;
	if (idx == 1)
		ra(a, cmd);
	if (idx == 2)
	{
		ra(a, cmd);
		ra(a, cmd);
	}
	if (idx == 3)
	{
		rra(a, cmd);
		rra(a, cmd);
	}
	if (idx == 4)
		rra(a, cmd);
	pb(a, b, cmd);
	free_strictly(&ranks);
}

void	push_five_b_to_a(t_deque *a, t_deque *b, t_deque *cmd)
{
	int	*ranks;
	int	idx;

	ranks = get_ranks(b, 5);
	idx = -1;
	while (ranks[++idx])
		if (ranks[idx] == 5)
			break ;
	if (idx == 1)
		rb(b, cmd, 0);
	if (idx == 2)
	{
		rb(b, cmd, 0);
		rb(b, cmd, 0);
	}
	if (idx == 3)
	{
		rrb(b, cmd, 0);
		rrb(b, cmd, 0);
	}
	if (idx == 4)
		rrb(b, cmd, 0);
	pa(a, b, cmd);
	free_strictly(&ranks);
}

void	sort_five_a(t_deque *a, t_deque *b, t_deque *cmd)
{
	push_one_a_to_b_2(a, b, cmd);
	push_one_or_two_a_to_b(a, b, cmd, 1);
	sort_three_below_a(a, cmd, 3);
	pa(a, b, cmd);
	pa(a, b, cmd);
}

void	sort_five_b(t_deque *a, t_deque *b, t_deque *cmd)
{
	push_five_b_to_a(a, b, cmd);
	push_four_b_to_a(a, b, cmd);
	sort_three_below_a(a, cmd, 3);
	pa(a, b, cmd);
	pa(a, b, cmd);
}

void	sort_four_a(t_deque *a, t_deque *b, t_deque *cmd)
{
	push_one_or_two_a_to_b(a, b, cmd, 1);
	sort_three_below_a(a, cmd, 3);
	pa(a, b, cmd);
}
