/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cmd.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sanan <sanan@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/02 22:35:13 by sanan			 #+#	#+#			 */
/*   Updated: 2023/01/04 16:39:04 by sanan			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd_by_flag(int flags)
{
	char	*flag_to_cmd;

	flag_to_cmd = NULL;
	if (flags == CMD_SA)
		flag_to_cmd = "sa\n";
	if (flags == CMD_SB)
		flag_to_cmd = "sb\n";
	if (flags == CMD_SS)
		flag_to_cmd = "ss\n";
	if (flags == CMD_PA)
		flag_to_cmd = "pa\n";
	if (flags == CMD_PB)
		flag_to_cmd = "pb\n";
	if (flag_to_cmd != NULL)
		ft_putstr_fd(flag_to_cmd, 1);
}

void	print_cmd_by_flag_2(int flags)
{
	char	*flag_to_cmd;

	flag_to_cmd = NULL;
	if (flags == CMD_RA)
		flag_to_cmd = "ra\n";
	if (flags == CMD_RB)
		flag_to_cmd = "rb\n";
	if (flags == CMD_RR)
		flag_to_cmd = "rr\n";
	if (flags == CMD_RRA)
		flag_to_cmd = "rra\n";
	if (flags == CMD_RRB)
		flag_to_cmd = "rrb\n";
	if (flags == CMD_RRR)
		flag_to_cmd = "rrr\n";
	if (flag_to_cmd != NULL)
		ft_putstr_fd(flag_to_cmd, 1);
}

void	print_cmd(t_deque *cmd)
{
	t_dlist	*head;

	head = cmd->front;
	while (head)
	{
		print_cmd_by_flag(head->content);
		print_cmd_by_flag_2(head->content);
		head = head->next;
	}
}

void	optimize_cmd(t_deque *cmd, t_dlist *node)
{
	int	count_optimize;

	count_optimize = 0;
	while (node->prev && count_optimize < 5)
	{
		if (optimize_concurrent_cmd(cmd, &node) == CMD_OPTIMIZE_SUCCESS)
			count_optimize++;
		if (optimize_meaningless_cmd(cmd, &node) == CMD_OPTIMIZE_SUCCESS)
			count_optimize++;
		if (node == NULL)
			break ;
		if (node->prev != NULL)
			node = node->prev;
	}
	if (node->prev == NULL && count_optimize == 0)
		return ;
	else
		optimize_cmd(cmd, cmd->rear);
}
