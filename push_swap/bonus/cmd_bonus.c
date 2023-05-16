/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:11:22 by sanan             #+#    #+#             */
/*   Updated: 2023/01/06 17:21:35 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_line(char *cmd, t_deque *a, t_deque *b, t_deque *command)
{
	if (cmd == NULL || cmd[0] == '\n')
		return ;
	if (!(ft_strncmp(cmd, "sa\n", 3) == 0 || \
		ft_strncmp(cmd, "sb\n", 3) == 0 || \
		ft_strncmp(cmd, "ss\n", 3) == 0 || \
		ft_strncmp(cmd, "ra\n", 3) == 0 || \
		ft_strncmp(cmd, "rb\n", 3) == 0 || \
		ft_strncmp(cmd, "rr\n", 3) == 0 || \
		ft_strncmp(cmd, "pa\n", 3) == 0 || \
		ft_strncmp(cmd, "pb\n", 3) == 0 || \
		ft_strncmp(cmd, "rra\n", 4) == 0 || \
		ft_strncmp(cmd, "rrb\n", 4) == 0 || \
		ft_strncmp(cmd, "rrr\n", 4) == 0))
	{
		free(cmd);
		free_deque(a);
		free_deque(b);
		free_deque(command);
		error_exit(ERR_CMD);
	}
}

void	do_as_input(char *input, t_deque *a, t_deque *b, t_deque *cmd)
{
	if (input == NULL)
		return ;
	if (ft_strncmp(input, "sa\n", 3) == 0)
		sa(a, cmd);
	if (ft_strncmp(input, "sb\n", 3) == 0)
		sb(b, cmd);
	if (ft_strncmp(input, "ss\n", 3) == 0)
		ss(a, b, cmd);
	if (ft_strncmp(input, "ra\n", 3) == 0)
		ra(a, cmd);
	if (ft_strncmp(input, "rb\n", 3) == 0)
		rb(b, cmd, 0);
	if (ft_strncmp(input, "rr\n", 3) == 0)
		rr(a, b, cmd);
	if (ft_strncmp(input, "pa\n", 3) == 0)
		pa(a, b, cmd);
	if (ft_strncmp(input, "pb\n", 3) == 0)
		pb(a, b, cmd);
	if (ft_strncmp(input, "rra\n", 4) == 0)
		rra(a, cmd);
	if (ft_strncmp(input, "rrb\n", 4) == 0)
		rrb(b, cmd, 0);
	if (ft_strncmp(input, "rrr\n", 4) == 0)
		rrr(a, b, cmd);
}

void	get_cmd(t_deque *a, t_deque *b, t_deque *cmd)
{
	char	*input;

	input = get_next_line(0);
	while (input != NULL)
	{
		check_line(input, a, b, cmd);
		do_as_input(input, a, b, cmd);
		free(input);
		input = get_next_line(0);
	}
	check_line(input, a, b, cmd);
	do_as_input(input, a, b, cmd);
	free(input);
	ft_putstr_fd(CYAN "####RESULT#####\n" RESET, STDOUT_FILENO);
	print_queue(a);
	if (check_is_sorted(a) == 1 && b->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_putstr_fd("CMD counts : ", STDOUT_FILENO);
	ft_putnbr_fd(cmd->size, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
