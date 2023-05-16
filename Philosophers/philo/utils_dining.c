/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 07:49:34 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 07:52:20 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		flag;
	int		dead;

	philo = arg;
	dead = FALSE;
	while (dead == FALSE)
	{
		flag = take_forks(philo);
		if (flag == FAILURE)
			return ((void *)THREAD_ERROR);
		if (flag == FALSE)
			break ;
		if (eat_and_release_forks(philo) == FAILURE)
			return ((void *)THREAD_ERROR);
		if (philo->count_to_eat == 0 || notice_dead_while_sleep(philo) == TRUE)
			break ;
		if (shout(philo, THINKING) == FAILURE)
			return ((void *)THREAD_ERROR);
		dead = is_anyone_dead(philo);
		if (dead == FAILURE)
			return ((void *)THREAD_ERROR);
	}
	return (NULL);
}

int	start_dinner_odd(t_table *table)
{
	int		count;
	t_philo	*philo;

	count = 0;
	while (count < table->number_of_philo)
	{
		philo = table->philos[count];
		if (pthread_create(&(philo->id), NULL, routine, philo) \
			!= SYSTEM_SUCCESS)
			return (FAILURE);
		count += 2;
	}
	return (TRUE);
}

int	start_dinner_even(t_table *table)
{
	int		count;
	t_philo	*philo;

	count = 1;
	while (count < table->number_of_philo)
	{
		philo = table->philos[count];
		if (pthread_create(&(philo->id), NULL, routine, philo) \
			!= SYSTEM_SUCCESS)
			return (FAILURE);
		count += 2;
	}
	return (TRUE);
}

int	wait_for_dinner_finished(t_table *table)
{
	int		count;
	t_philo	*philo;

	count = 0;
	while (count < table->number_of_philo)
	{
		philo = table->philos[count];
		if (pthread_join(philo->id, NULL) != SYSTEM_SUCCESS)
			return (FAILURE);
		count++;
	}
	return (TRUE);
}

int	dining(t_table *table, t_info *info)
{
	if (start_dinner_odd(table) == FAILURE)
		return (FAILURE);
	if (take_time(info->time_to_eat) == FAILURE)
		return (FAILURE);
	if (start_dinner_even(table) == FAILURE)
		return (FAILURE);
	if (wait_for_dinner_finished(table) == FAILURE)
		return (FAILURE);
	return (TRUE);
}
