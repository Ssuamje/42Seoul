/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:41:33 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 21:00:13 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimize_meaningess_push(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_PA && (*node)->prev->content == CMD_PB) || \
		((*node)->content == CMD_PB && (*node)->prev->content == CMD_PA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_meaningless_rotate(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_RA && (*node)->prev->content == CMD_RRA) || \
		((*node)->content == CMD_RRA && (*node)->prev->content == CMD_RA) || \
		((*node)->content == CMD_RRB && (*node)->prev->content == CMD_RB) || \
		((*node)->content == CMD_RB && (*node)->prev->content == CMD_RRB))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_meaningless_rotate_2(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_RA && (*node)->prev->content == CMD_RRR) || \
		((*node)->content == CMD_RRR && (*node)->prev->content == CMD_RA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_RRB;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	if (((*node)->content == CMD_RB && (*node)->prev->content == CMD_RRR) || \
		((*node)->content == CMD_RRR && (*node)->prev->content == CMD_RB))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_RRA;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_meaningless_rrotate_2(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_RRA && (*node)->prev->content == CMD_RR) || \
		((*node)->content == CMD_RR && (*node)->prev->content == CMD_RRA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_RB;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	if (((*node)->content == CMD_RRB && (*node)->prev->content == CMD_RR) || \
		((*node)->content == CMD_RR && (*node)->prev->content == CMD_RRB))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_RA;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_rr_rrr(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_RR && (*node)->prev->content == CMD_RRR) || \
		((*node)->content == CMD_RRR && (*node)->prev->content == CMD_RR))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}
