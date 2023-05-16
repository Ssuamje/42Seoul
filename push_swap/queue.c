/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:36:24 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 00:04:29 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*new_dlist(int content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		error_exit(ERR_LIST);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	delone_dlist(t_dlist **to_del)
{
	(*to_del)->next = 0;
	(*to_del)->prev = 0;
	free(*to_del);
	to_del = NULL;
}

t_deque	*init_deque(void)
{
	t_deque	*deq;

	deq = malloc(sizeof(t_deque));
	if (deq == NULL)
		error_exit(ERR_ALLOC);
	deq->front = NULL;
	deq->rear = NULL;
	deq->size = 0;
	return (deq);
}
