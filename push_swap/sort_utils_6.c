/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:01:28 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 21:49:48 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_sa_rra(t_deque *a, t_deque *cmd)
{
	ra(a, cmd);
	sa(a, cmd);
	rra(a, cmd);
}

void	sort_231_a_above(t_deque *a, t_deque *cmd)
{
	ra_sa_rra(a, cmd);
	sa(a, cmd);
}

void	sort_312_a_above(t_deque *a, t_deque *cmd)
{
	sa(a, cmd);
	ra_sa_rra(a, cmd);
}

void	sort_321_a_above(t_deque *a, t_deque *cmd)
{
	sa(a, cmd);
	ra_sa_rra(a, cmd);
	sa(a, cmd);
}

void	sort_three_below_a_above(t_deque *a, t_deque *cmd)
{
	int	*ranks;

	ranks = NULL;
	if (a->size == 2 && a->front->next->content < a->front->content)
		sa(a, cmd);
	if (a->size >= 3)
	{
		ranks = get_ranks(a, 3);
		if (ranks[0] == 1 && ranks[1] == 3)
			ra_sa_rra(a, cmd);
		if (ranks[0] == 2 && ranks[1] == 1)
			sa(a, cmd);
		if (ranks[0] == 2 && ranks[1] == 3)
			sort_231_a_above(a, cmd);
		if (ranks[0] == 3 && ranks[1] == 1)
			sort_312_a_above(a, cmd);
		if (ranks[0] == 3 && ranks[1] == 2)
			sort_321_a_above(a, cmd);
	}
	free_strictly(&ranks);
}
