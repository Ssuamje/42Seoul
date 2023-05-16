/* ************************************************************************** */
/*															 */
/*											 :::	 ::::::::   */
/*   parse.c								    :+:	 :+:    :+:   */
/*										  +:+ +:+	    +:+	*/
/*   By: sanan <sanan@student.42seoul.kr>		 +#+  +:+	  +#+	   */
/*									   +#+#+#+#+#+   +#+		 */
/*   Created: 2022/12/29 22:15:35 by sanan		   #+#    #+#		   */
/*   Updated: 2023/01/04 16:44:13 by sanan		  ###   ########.fr	  */
/*															 */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_value_duplicated(int value_to_put, t_deque *deq)
{
	t_dlist	*tmp;

	tmp = deq->front;
	while (tmp)
	{
		if (tmp->content == value_to_put)
			error_exit(ERR_VALUE_DUPLICATED);
		tmp = tmp->next;
	}
}

void	check_and_push(char *arg, t_deque *deq)
{
	char	**splitted;
	int		idx;
	int		value_to_put;
	t_dlist	*node_to_push;

	splitted = ft_split(arg, ' ');
	if (splitted == NULL)
		error_exit(ERR_ALLOC);
	idx = 0;
	while (is_split_ok(splitted[idx]) != NULL)
	{
		value_to_put = ft_pssw_atoi(splitted[idx]);
		check_value_duplicated(value_to_put, deq);
		node_to_push = new_dlist(value_to_put);
		push_right(node_to_push, deq);
		idx++;
	}
	if (splitted[idx] != NULL)
		error_exit(ERR_SPLIT_CHUNK);
	free_split(&splitted);
}

void	check_av_str(char *av_str)
{
	if (av_str[0] == '\0' || \
		is_str_only_white_spaces(av_str))
		error_exit(ERR_ARGUMENT_EMPTY);
}

int	check_is_sorted(t_deque *deq)
{
	int		content_curr;
	int		content_next;
	t_dlist	*tmp;

	if (deq->front == NULL)
		return (1);
	tmp = deq->front;
	while (tmp->next)
	{
		content_curr = tmp->content;
		content_next = tmp->next->content;
		if (content_curr > content_next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_deque	*set_deque(int ac, char **av)
{
	t_deque	*deq;
	int		idx;

	deq = init_deque();
	if (deq == NULL)
		error_exit(ERR_DEQ);
	idx = 1;
	while (idx < ac)
	{
		check_av_str(av[idx]);
		check_and_push(av[idx], deq);
		idx++;
	}
	return (deq);
}
