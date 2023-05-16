/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:50:04 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 14:49:30 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_forks_on_table(t_table *table)
{
	t_fork	**forks_to_put;
	int		idx;

	forks_to_put = malloc(sizeof(t_fork *) * (table->number_of_philo));
	if (forks_to_put == NULL)
		return (FALSE);
	idx = 0;
	while (idx < table->number_of_philo)
	{
		forks_to_put[idx] = malloc(sizeof(t_fork));
		if (forks_to_put[idx] == NULL)
			return (FALSE);
		forks_to_put[idx]->status = RELEASED;
		if (pthread_mutex_init(&(forks_to_put[idx]->access), NULL) \
								!= SYSTEM_SUCCESS)
			return (FALSE);
		idx++;
	}
	table->forks = forks_to_put;
	return (TRUE);
}

int	init_table(t_table **table, char **av)
{
	*table = malloc(sizeof(t_table));
	if (*table == NULL)
		return (QUIT_TABLE);
	(*table)->number_of_philo = philo_atoi(av[1]);
	if (set_forks_on_table(*table) == FALSE)
		return (QUIT_FORK);
	return (TRUE);
}

int	inform_to_philo(t_philo *philo, t_info *info)
{
	philo->time_to_die = info->time_to_die;
	philo->time_to_eat = info->time_to_eat;
	philo->time_to_sleep = info->time_to_sleep;
	philo->has_count_eat = info->has_count_eat;
	philo->megaphone = &(info->megaphone);
	philo->check_death = &(info->check_death);
	philo->is_anyone_dead = &(info->is_anyone_dead);
	if (philo->has_count_eat == TRUE)
		philo->count_to_eat = info->count_to_eat;
	else
		philo->count_to_eat = UINT64_MAX;
	philo->last_eat_time = get_time();
	if (philo->last_eat_time == FALSE)
		return (FAILURE);
	philo->start_time = get_time();
	if (philo->start_time == FALSE)
		return (FAILURE);
	return (TRUE);
}

int	sit_philos(t_table *table, t_info *info)
{
	int		idx;
	t_philo	**philos;

	idx = 0;
	philos = malloc(sizeof(t_philo *) * table->number_of_philo);
	if (philos == NULL)
		return (QUIT_PHILOS);
	while (idx < table->number_of_philo)
	{
		philos[idx] = malloc(sizeof(t_philo));
		if (philos[idx] == NULL)
			return (free_philo_each(philos, idx));
		if (inform_to_philo(philos[idx], info) == FAILURE)
			return (FAILURE);
		philos[idx]->num = idx + 1;
		philos[idx]->fork_left = table->forks[idx % table->number_of_philo];
		philos[idx]->fork_right = table->forks[(idx + 1) \
								% table->number_of_philo];
		idx++;
	}
	table->philos = philos;
	return (TRUE);
}

int	set_info(t_info **info, char **av)
{
	*info = malloc(sizeof(t_info));
	if (*info == NULL)
		return (QUIT_INFO);
	(*info)->time_to_die = philo_atoi(av[2]);
	(*info)->time_to_eat = philo_atoi(av[3]);
	(*info)->time_to_sleep = philo_atoi(av[4]);
	(*info)->is_anyone_dead = FALSE;
	(*info)->count_to_eat = UINT64_MAX;
	if (av[5])
	{
		(*info)->count_to_eat = philo_atoi(av[5]);
		(*info)->has_count_eat = TRUE;
	}
	else
		(*info)->has_count_eat = FALSE;
	if (pthread_mutex_init(&((*info)->megaphone), NULL) != SYSTEM_SUCCESS \
	|| pthread_mutex_init(&((*info)->check_death), NULL) != SYSTEM_SUCCESS)
		return (QUIT_INFO_MUTEX);
	return (TRUE);
}
