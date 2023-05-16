/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:19:56 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:42:39 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_sb_rrb(t_deque *b, t_deque *cmd)
{
	rb(b, cmd, 0);
	sb(b, cmd);
	rrb(b, cmd, 0);
}

void	sort_213_b_above(t_deque *b, t_deque *cmd)
{
	rb_sb_rrb(b, cmd);
	sb(b, cmd);
}

void	sort_132_b_above(t_deque *b, t_deque *cmd)
{
	sb(b, cmd);
	rb_sb_rrb(b, cmd);
}

void	sort_123_b_above(t_deque *b, t_deque *cmd)
{
	sb(b, cmd);
	rb_sb_rrb(b, cmd);
	sb(b, cmd);
}

void	sort_three_below_b_above(t_deque *b, t_deque *cmd)
{
	int	*ranks;

	ranks = NULL;
	if (b->size >= 3)
	{
		ranks = get_ranks(b, 3);
		if (ranks[0] == 1 && ranks[1] == 2)
			sort_123_b_above(b, cmd);
		if (ranks[0] == 1 && ranks[1] == 3)
			sort_132_b_above(b, cmd);
		if (ranks[0] == 2 && ranks[1] == 1)
			sort_213_b_above(b, cmd);
		if (ranks[0] == 2 && ranks[1] == 3)
			sb(b, cmd);
		if (ranks[0] == 3 && ranks[1] == 1)
			rb_sb_rrb(b, cmd);
	}
	free_strictly(&ranks);
}
