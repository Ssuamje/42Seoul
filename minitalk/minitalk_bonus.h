/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:54:33 by sanan             #+#    #+#             */
/*   Updated: 2022/12/28 22:10:08 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_WHITE	"\x1B[37m"
# define COLOR_RESET	"\x1b[0m"

typedef struct s_status{
	int		is_server_received;
	pid_t	pid_server;
}	t_status;

typedef struct sigaction	t_sa;

enum e_bool{
	FAILURE_SA = -1,
	FAILURE,
	SUCCESS
};

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		put_error(char *msg);
void	put_pid(pid_t pid);

#endif