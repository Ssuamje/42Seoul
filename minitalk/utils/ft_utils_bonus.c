/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:28:02 by sanan             #+#    #+#             */
/*   Updated: 2022/12/29 07:43:03 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	put_pid(pid_t pid)
{
	ft_putstr_fd(COLOR_BLUE "->SERVER PID = " COLOR_YELLOW, STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putstr_fd(COLOR_BLUE "<-\n" COLOR_GREEN, STDOUT_FILENO);
}

int	put_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (FAILURE);
}
