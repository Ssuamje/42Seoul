/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:10:16 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 11:16:07 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_deque *a, t_deque *cmd)
{
	int	tmp;

	if (a->size <= 1)
	{
		push_right(new_dlist(CMD_SA), cmd);
		return ;
	}
	tmp = a->front->content;
	a->front->content = a->front->next->content;
	a->front->next->content = tmp;
	push_right(new_dlist(CMD_SA), cmd);
}

void	sb(t_deque *b, t_deque *cmd)
{
	int	tmp;

	if (b->size <= 1)
	{
		push_right(new_dlist(CMD_SB), cmd);
		return ;
	}
	tmp = b->front->content;
	b->front->content = b->front->next->content;
	b->front->next->content = tmp;
	push_right(new_dlist(CMD_SB), cmd);
}

void	ss(t_deque *a, t_deque *b, t_deque *cmd)
{
	int	tmp;

	if (a->size <= 1)
	{
		push_right(new_dlist(CMD_SS), cmd);
		return ;
	}
	tmp = a->front->content;
	a->front->content = a->front->next->content;
	a->front->next->content = tmp;
	if (b->size <= 1)
	{
		push_right(new_dlist(CMD_SS), cmd);
		return ;
	}
	tmp = b->front->content;
	b->front->content = b->front->next->content;
	b->front->next->content = tmp;
	push_right(new_dlist(CMD_SS), cmd);
}

void	pa(t_deque *a, t_deque *b, t_deque *cmd)
{
	if (b->size == 0)
	{
		push_right(new_dlist(CMD_PA), cmd);
		return ;
	}
	push_left(new_dlist(b->front->content), a);
	pop_left(b);
	push_right(new_dlist(CMD_PA), cmd);
}

void	pb(t_deque *a, t_deque *b, t_deque *cmd)
{
	if (a->size == 0)
	{
		push_right(new_dlist(CMD_PA), cmd);
		return ;
	}
	push_left(new_dlist(a->front->content), b);
	pop_left(a);
	push_right(new_dlist(CMD_PB), cmd);
}
