/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sanan <sanan@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/30 16:27:08 by sanan			 #+#	#+#			 */
/*   Updated: 2023/01/04 15:58:21 by sanan			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_deque *deq)
{
	t_dlist	*tmp_lst;
	int		tmp_content;

	tmp_lst = deq->rear;
	while (tmp_lst->prev)
	{
		tmp_content = tmp_lst->content;
		tmp_lst->content = tmp_lst->prev->content;
		tmp_lst->prev->content = tmp_content;
		tmp_lst = tmp_lst->prev;
	}
}

void	rra(t_deque *a, t_deque *cmd)
{
	if (a->size <= 1)
		return (push_right(new_dlist(CMD_RRA), cmd));
	rrotate(a);
	push_right(new_dlist(CMD_RRA), cmd);
}

void	rrb(t_deque *b, t_deque *cmd, int is_chained)
{
	if (b->size <= 1)
		return (push_right(new_dlist(CMD_RRB), cmd));
	rrotate(b);
	if (is_chained != 1)
		push_right(new_dlist(CMD_RRB), cmd);
}

void	rrr(t_deque *a, t_deque *b, t_deque *cmd)
{
	if (a->size <= 1)
	{
		if (b->size > 1)
			rrb(b, cmd, 1);
		return (push_right(new_dlist(CMD_RRR), cmd));
	}
	rrotate(a);
	if (b->size <= 1)
		return (push_right(new_dlist(CMD_RRR), cmd));
	rrotate(b);
	push_right(new_dlist(CMD_RRR), cmd);
}
