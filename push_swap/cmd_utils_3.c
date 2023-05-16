/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:42:29 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 21:00:15 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimize_concurrent_cmd(t_deque *cmd, t_dlist **node)
{
	if (optimize_concurrent_swap(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_concurrent_rotate(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_concurrent_rrotate(cmd, node) == CMD_OPTIMIZE_SUCCESS)
		return (CMD_OPTIMIZE_SUCCESS);
	return (CMD_NOT_OPTIMIZED);
}

int	optimize_meaningless_cmd(t_deque *cmd, t_dlist **node)
{
	if (optimize_meaningless_swap(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_meaningless_swap_2(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_meaningess_push(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_meaningless_rotate(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_meaningless_rotate_2(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_meaningless_rrotate_2(cmd, node) == CMD_OPTIMIZE_SUCCESS || \
		optimize_rr_rrr(cmd, node) == CMD_OPTIMIZE_SUCCESS)
		return (CMD_OPTIMIZE_SUCCESS);
	return (CMD_NOT_OPTIMIZED);
}
