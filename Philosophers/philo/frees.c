/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:49:27 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 07:58:05 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_forks(t_fork **forks, int number_of_philo)
{
	int	idx;

	idx = 0;
	while (idx < number_of_philo)
	{
		if (pthread_mutex_destroy(&(forks[idx])->access) == FAILURE)
			return (FAILURE);
		free(forks[idx++]);
	}
	free(forks);
	return (TRUE);
}

int	free_philo_each(t_philo **philos, int stopped)
{
	int	idx;

	idx = 0;
	while (idx < stopped)
		if (philos[idx] != NULL)
			free(philos[idx++]);
	return (QUIT_PHILO_EACH);
}

int	cleaning(t_table *table, t_info *info)
{
	free_forks(table->forks, table->number_of_philo);
	free_philo_each(table->philos, table->number_of_philo);
	free(table->philos);
	free(table);
	if (pthread_mutex_destroy(&(info->check_death)) == FAILURE)
		return (FAILURE);
	if (pthread_mutex_destroy(&(info->megaphone)) == FAILURE)
		return (FAILURE);
	free(info);
	return (FAILURE);
}

int	quit_program(int quit_flag, t_table *table, t_info *info)
{
	print_by_flag(quit_flag);
	if (quit_flag == QUIT_ARGS || quit_flag == QUIT_ATOI)
		return (EXIT_FAILURE);
	if (quit_flag == QUIT_INFO)
	{
		free(info);
		return (EXIT_FAILURE);
	}
	pthread_mutex_destroy(&(info->megaphone));
	pthread_mutex_destroy(&(info->check_death));
	free(info);
	if (quit_flag == QUIT_FORK || quit_flag == QUIT_PHILOS)
	{
		free_forks(table->forks, table->number_of_philo);
		free(table);
	}
	if (quit_flag == QUIT_PHILO_EACH)
	{
		free_forks(table->forks, table->number_of_philo);
		free(table->philos);
		free(table);
	}
	return (EXIT_FAILURE);
}
