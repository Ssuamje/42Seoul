/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:27:20 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 23:09:07 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*make_ranks(t_deque *deq, int *ranks, int counts)
{
	t_dlist	*check_tmp;
	t_dlist	*find_tmp;
	int		idx;
	int		jdx;

	check_tmp = deq->front;
	find_tmp = deq->front->next;
	idx = -1;
	while (++idx < counts)
	{
		jdx = -1;
		find_tmp = deq->front;
		while (++jdx < counts)
		{
			if (check_tmp->content > find_tmp->content)
				(ranks[idx])++;
			find_tmp = find_tmp->next;
		}
		check_tmp = check_tmp->next;
	}
	return (ranks);
}

int	*get_ranks(t_deque *deq, int counts)
{
	int		*ranks;
	int		idx;

	if (deq->size == 0)
		return (NULL);
	ranks = malloc(sizeof(int) * counts);
	if (ranks == NULL)
		error_exit(ERR_ALLOC);
	idx = 0;
	while (idx < counts)
		ranks[idx++] = 1;
	return (make_ranks(deq, ranks, counts));
}

void	set_ranks(t_deque *deq, int *ranks)
{
	t_dlist	*tmp;
	int		idx;

	tmp = deq->front;
	idx = 0;
	while (idx < deq->size)
	{
		tmp->content = ranks[idx++];
		tmp = tmp->next;
	}
}

void	free_strictly(int **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
