/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:16:39 by sanan             #+#    #+#             */
/*   Updated: 2022/12/28 21:40:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sig_to_bit(int sig)
{
	if (sig == SIGUSR1)
		return (0);
	else
		return (1);
}

char	convert_bits_to_byte(int *bits)
{
	char	ret;
	int		idx;

	ret = 0;
	idx = 0;
	while (idx < 8)
	{
		if (bits[idx] == 1)
			ret |= (1 << idx);
		idx++;
	}
	return (ret);
}

void	sa_server_handler(int sig, struct __siginfo *siginfo, void *context)
{
	char		byte;
	static int	bits[8];
	static int	count;

	(void)context;
	if (siginfo->si_pid == 0)
		return ;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		bits[count] = sig_to_bit(sig);
		count++;
		if (count == 8)
		{
			count = 0;
			byte = convert_bits_to_byte(bits);
			write(STDOUT_FILENO, &byte, 1);
		}
		kill(siginfo->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	t_sa	sa_server;

	put_pid(getpid());
	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = sa_server_handler;
	sigemptyset(&(sa_server.sa_mask));
	if (sigaction(SIGUSR1, &sa_server, NULL) == FAILURE_SA || \
		sigaction(SIGUSR2, &sa_server, NULL) == FAILURE_SA)
		return (put_error("Error : Connection Failed.\n"));
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
