/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:21:08 by sanan             #+#    #+#             */
/*   Updated: 2023/01/06 17:21:03 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_deque(t_deque *deq)
{
	t_dlist	*head;
	t_dlist	*tmp;

	if (deq == NULL)
		return ;
	head = deq->front;
	while (head)
	{
		if (head->next)
		{
			tmp = head->next;
			delone_dlist(&head);
			head = tmp;
		}
		else
			break ;
	}
	if (head != NULL)
		delone_dlist(&head);
	free(deq);
}

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;
	t_deque	*cmd;

	if (ac == 1 || av == NULL)
		exit(EXIT_SUCCESS);
	if (ac > ARG_MAX)
		error_exit(ERR_ARGUMENT_COUNTS);
	a = set_deque(ac, av);
	b = init_deque();
	cmd = init_deque();
	ft_putstr_fd(CYAN "#A before sort#\n" RESET, 1);
	print_queue(a);
	get_cmd(a, b, cmd);
	free_deque(a);
	free_deque(b);
	free_deque(cmd);
	return (0);
}
