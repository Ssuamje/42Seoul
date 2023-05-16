/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:04:22 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 07:54:43 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_anyone_dead(t_philo *philo)
{
	int	ret;

	if (pthread_mutex_lock(philo->check_death) != SYSTEM_SUCCESS)
		return (FAILURE);
	ret = *(philo->is_anyone_dead);
	if (pthread_mutex_unlock(philo->check_death) != SYSTEM_SUCCESS)
		return (FAILURE);
	return (ret);
}

int	mark_death(t_philo *philo)
{
	if (pthread_mutex_lock(philo->check_death) != SYSTEM_SUCCESS)
		return (FAILURE);
	*(philo->is_anyone_dead) = TRUE;
	if (pthread_mutex_unlock(philo->check_death) != SYSTEM_SUCCESS)
		return (FAILURE);
	return (TRUE);
}

int	am_i_dead(t_philo *philo)
{
	uint64_t	now;
	int			err;

	now = get_time();
	if (now == FALSE)
		return (FAILURE);
	if ((now - philo->last_eat_time) >= (uint64_t)philo->time_to_die)
	{
		err = shout(philo, DEAD);
		if (err == FAILURE)
			return (FAILURE);
		return (TRUE);
	}
	else
		return (FALSE);
}

int	if_dead_notice_death(t_philo *philo)
{
	int	dead;
	int	me_dead;

	dead = is_anyone_dead(philo);
	if (dead == FAILURE)
		return (FAILURE);
	if (dead == TRUE)
		return (TRUE);
	else
	{
		me_dead = am_i_dead(philo);
		if (me_dead == FAILURE)
			return (FAILURE);
		if (me_dead == TRUE)
			return (TRUE);
		else
			return (FALSE);
	}
}
