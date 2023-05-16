/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:05:29 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 15:07:48 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_by_flag(int quit_flag)
{
	if (quit_flag == QUIT_ARGS)
		printf("Error: Argmuents count must be 4 ~ 5!\n");
	if (quit_flag == QUIT_ATOI)
		printf("Error: Arguments are invalid!\n");
	if (quit_flag == QUIT_FORK)
		printf("Error: Error occured while setting forks.\n");
	if (quit_flag == QUIT_TABLE)
		printf("Error: Error occured while setting table.\n");
	if (quit_flag == QUIT_INFO)
		printf("Error: Error occured while writing info.\n");
	if (quit_flag == QUIT_INFO_MUTEX)
		printf("Error: Error occured while setting shared properties.\n");
	if (quit_flag == QUIT_PHILOS)
		printf("Error: Error occcured while calling philos!\n");
	if (quit_flag == QUIT_PHILO_EACH)
		printf("Error: Error occured while calling each philo!\n");
}

char	*msg(int status)
{
	if (status == DEAD)
		return ("died\n");
	if (status == TAKEN_FORK)
		return ("has taken a fork\n");
	if (status == EATING)
		return ("is eating\n");
	if (status == THINKING)
		return ("is thinking\n");
	if (status == SLEEPING)
		return ("is sleeping\n");
	return (NULL);
}

int	shout(t_philo *philo, int status)
{
	int			dead;
	uint64_t	time;

	if (pthread_mutex_lock(philo->megaphone) != SYSTEM_SUCCESS)
		return (FAILURE);
	dead = is_anyone_dead(philo);
	if (dead == FAILURE)
		return (FALSE);
	if (dead == FALSE)
	{
		if (status == DEAD)
		{
			dead = mark_death(philo);
			if (dead == FAILURE)
				return (FAILURE);
		}
		time = get_time();
		if (time == FALSE)
			return (FAILURE);
		printf("%llu %d %s", time - philo->start_time, philo->num, msg(status));
	}
	if (pthread_mutex_unlock(philo->megaphone) != SYSTEM_SUCCESS)
		return (FAILURE);
	return (TRUE);
}
