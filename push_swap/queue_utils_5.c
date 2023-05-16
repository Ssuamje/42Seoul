/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:26:12 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 16:26:20 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	connect_besides_and_free(t_deque *deq, t_dlist *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delone_dlist(&node);
	(deq->size)--;
}

t_dlist	*pop_node(t_deque *deq, t_dlist *node, int to_return)
{
	t_dlist	*prev;
	t_dlist	*next;

	if (deq->size == 0 || node == NULL)
		return (NULL);
	prev = node->prev;
	next = node->next;
	if (node->next == NULL)
	{
		pop_right(deq);
		return (deq->rear);
	}
	else if (node->prev == NULL)
	{
		pop_left(deq);
		return (deq->front);
	}
	else
		connect_besides_and_free(deq, node);
	if (to_return == POP_RETURN_PREV && prev)
		return (prev);
	else if (to_return == POP_RETURN_NEXT && next)
		return (next);
	else
		return (NULL);
}
