/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:23:31 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 11:38:44 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_len(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int	count_digit(long long num)
{
	int	i;

	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i = 1;
	}
	else
		i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

void	print_queue(t_deque *deq)
{
	t_dlist	*head;
	int		blank;
	int		digit;

	head = deq->front;
	ft_putstr_fd(GREEN "#######", STDOUT_FILENO);
	ft_putstr_fd(YELLOW "A", STDOUT_FILENO);
	ft_putstr_fd(GREEN "#######\n", STDOUT_FILENO);
	while (head)
	{
		blank = 12;
		digit = count_digit(head->content);
		ft_putstr_fd(GREEN "| ", STDOUT_FILENO);
		while (--blank > digit)
			ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(head->content, STDOUT_FILENO);
		ft_putstr_fd(" |\n", STDOUT_FILENO);
		head = head->next;
	}
	ft_putstr_fd("###############\n", STDOUT_FILENO);
	ft_putstr_fd(GREEN "size = ", STDOUT_FILENO);
	ft_putnbr_fd(deq->size, STDOUT_FILENO);
	ft_putstr_fd("\n###############\n" RESET, STDOUT_FILENO);
}
