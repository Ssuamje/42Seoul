/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:16:39 by sanan             #+#    #+#             */
/*   Updated: 2022/12/29 07:44:38 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_status	g_status;

void	sa_client_handler(int sig, struct __siginfo *siginfo, void *context)
{
	(void)context;
	if (siginfo->si_pid == 0)
		return ;
	if (sig == SIGUSR1)
		g_status.is_server_received = SUCCESS;
}

int	bit_to_sig(int bit)
{
	if (bit == 1)
		return (SIGUSR2);
	else
		return (SIGUSR1);
}

void	split_byte_to_bits(int *bits, char to_bitizate)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		bits[idx] = to_bitizate & 1;
		to_bitizate >>= 1;
		idx++;
	}
}

void	send_str(const char *str_to_send)
{
	char	byte_to_split;
	int		idx;
	int		bits[8];
	int		count;

	g_status.is_server_received = SUCCESS;
	idx = 0;
	while (str_to_send[idx])
	{
		byte_to_split = str_to_send[idx];
		split_byte_to_bits(bits, byte_to_split);
		count = 0;
		while (count < 8)
		{
			if (g_status.is_server_received == SUCCESS)
			{
				g_status.is_server_received = FAILURE;
				usleep(100);
				kill(g_status.pid_server, bit_to_sig(bits[count]));
				count++;
			}
		}
		idx++;
	}
}

int	main(int ac, char **av)
{
	t_sa		sa_client;
	const char	*str_to_send;

	if (ac != 3)
		return (put_error("Error : Client program needs two arguments \
							- \"server_pid\" \"message_to_send\"\n"));
	g_status.pid_server = ft_atoi(av[1]);
	if (g_status.pid_server <= 100 || g_status.pid_server >= 100000)
		return (put_error("Error : Wrong PID!\n"));
	str_to_send = av[2];
	sa_client.sa_flags = 0;
	sa_client.sa_sigaction = sa_client_handler;
	sigemptyset(&sa_client.sa_mask);
	if (sigaction(SIGUSR1, &sa_client, NULL) == FAILURE_SA)
		return (put_error("Error : Connection Failed.\n"));
	send_str(str_to_send);
	return (EXIT_SUCCESS);
}
