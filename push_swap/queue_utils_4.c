/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:49:33 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 16:26:09 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	push_left(t_dlist *node_to_push, t_deque *deq)
{
	if (deq->size == 0)
	{
		deq->rear = node_to_push;
		deq->front = node_to_push;
		(deq->size)++;
	}
	else
	{
		deq->front->prev = node_to_push;
		node_to_push->next = deq->front;
		deq->front = node_to_push;
		(deq->size)++;
	}
}

void	push_right(t_dlist *node_to_push, t_deque *deq)
{
	if (deq->size == 0)
	{
		deq->front = node_to_push;
		deq->rear = node_to_push;
		(deq->size)++;
	}
	else
	{
		deq->rear->next = node_to_push;
		node_to_push->prev = deq->rear;
		deq->rear = node_to_push;
		(deq->size)++;
	}
}

void	pop_left(t_deque *deq)
{
	t_dlist	*tmp;

	if (deq->size == 0)
		return ;
	if (deq->size == 1)
	{
		delone_dlist(&(deq->front));
		deq->front = NULL;
		deq->rear = NULL;
		(deq->size)--;
	}
	else
	{
		deq->front->next->prev = NULL;
		tmp = deq->front->next;
		delone_dlist(&(deq->front));
		deq->front = tmp;
		(deq->size)--;
	}
}

void	pop_right(t_deque *deq)
{
	t_dlist	*tmp;

	if (deq->size == 0)
		return ;
	if (deq->size == 1)
	{
		delone_dlist(&(deq->rear));
		deq->front = NULL;
		deq->rear = NULL;
		(deq->size)--;
	}
	else
	{
		deq->rear->prev->next = NULL;
		tmp = deq->rear->prev;
		delone_dlist(&(deq->rear));
		deq->rear = tmp;
		(deq->size)--;
	}
}
