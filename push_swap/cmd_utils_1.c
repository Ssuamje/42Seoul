/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:40:53 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 21:00:12 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimize_concurrent_swap(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_SA && (*node)->prev->content == CMD_SB) || \
		((*node)->content == CMD_SB && (*node)->prev->content == CMD_SA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_SS;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_concurrent_rotate(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_RA && (*node)->prev->content == CMD_RB) || \
		((*node)->content == CMD_RB && (*node)->prev->content == CMD_RA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_RR;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_concurrent_rrotate(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_RRA && (*node)->prev->content == CMD_RRB) || \
		((*node)->content == CMD_RRB && (*node)->prev->content == CMD_RRA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_RRR;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_meaningless_swap(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_SA && (*node)->prev->content == CMD_SA) || \
		((*node)->content == CMD_SB && (*node)->prev->content == CMD_SB))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_meaningless_swap_2(t_deque *cmd, t_dlist **node)
{
	if (((*node)->content == CMD_SA && (*node)->prev->content == CMD_SS) || \
		((*node)->content == CMD_SS && (*node)->prev->content == CMD_SA))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_SB;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	if (((*node)->content == CMD_SB && (*node)->prev->content == CMD_SS) || \
		((*node)->content == CMD_SS && (*node)->prev->content == CMD_SB))
	{
		*node = pop_node(cmd, *node, POP_RETURN_PREV);
		(*node)->content = CMD_SA;
		if ((*node)->next != NULL)
			*node = (*node)->next;
		return (CMD_OPTIMIZE_SUCCESS);
	}
	return (CMD_NOT_OPTIMIZED);
}
