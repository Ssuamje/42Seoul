/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:10:45 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:33:02 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_deque *deq)
{
	t_dlist	*tmp_lst;
	int		tmp_content;

	tmp_lst = deq->front;
	while (tmp_lst->next)
	{
		tmp_content = tmp_lst->content;
		tmp_lst->content = tmp_lst->next->content;
		tmp_lst->next->content = tmp_content;
		tmp_lst = tmp_lst->next;
	}
}

void	ra(t_deque *a, t_deque *cmd)
{
	if (a->size <= 1)
		return (push_right(new_dlist(CMD_RA), cmd));
	rotate(a);
	push_right(new_dlist(CMD_RA), cmd);
}

void	rb(t_deque *b, t_deque *cmd, int is_chained)
{
	if (b->size <= 1)
		return (push_right(new_dlist(CMD_RB), cmd));
	rotate(b);
	if (is_chained != 1)
		push_right(new_dlist(CMD_RB), cmd);
}

void	rr(t_deque *a, t_deque *b, t_deque *cmd)
{
	if (a->size <= 1)
	{
		if (b->size > 1)
			rb(b, cmd, 1);
		return (push_right(new_dlist(CMD_RR), cmd));
	}
	rotate(a);
	if (b->size <= 1)
		return (push_right(new_dlist(CMD_RR), cmd));
	rotate(b);
	push_right(new_dlist(CMD_RR), cmd);
}
