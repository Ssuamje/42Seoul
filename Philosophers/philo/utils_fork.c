/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:06:21 by sanan             #+#    #+#             */
/*   Updated: 2023/06/20 13:01:39 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	try_to_hold_fork(t_fork *fork)
{
	if (fork->status == RELEASED)
	{
		fork->status = HELD;
		return (TRUE);
	}
	return (FALSE);
}

int	take_left_fork(t_philo *philo)
{
	int	dead;

	while (TRUE)
	{
		dead = if_dead_notice_death(philo);
		if (dead == FAILURE)
			return (FAILURE);
		if (dead == TRUE)
			return (FALSE);
		if (pthread_mutex_lock(&(philo->fork_left->access)) == FAILURE)
			return (FAILURE);
		if (try_to_hold_fork(philo->fork_left) == TRUE)
		{
			if (pthread_mutex_unlock(&(philo->fork_left->access)) == FAILURE)
				return (FAILURE);
			if (shout(philo, TAKEN_FORK) == FAILURE)
				return (FAILURE);
			return (TRUE);
		}
		if (pthread_mutex_unlock(&(philo->fork_left->access)) == FAILURE)
			return (FAILURE);
		if (usleep(1) == FAILURE)
			return (FAILURE);
	}
}

int	take_right_fork(t_philo *philo)
{
	while (TRUE)
	{
		if (if_dead_notice_death(philo) == TRUE)
			return (FALSE);
		if (pthread_mutex_lock(&(philo->fork_right->access)) == FAILURE)
			return (FAILURE);
		if (try_to_hold_fork(philo->fork_right) == TRUE)
		{
			if (pthread_mutex_unlock(&(philo->fork_right->access)) == FAILURE)
				return (FAILURE);
			if (shout(philo, TAKEN_FORK) == FAILURE)
				return (FAILURE);
			return (TRUE);
		}
		if (pthread_mutex_unlock(&(philo->fork_right->access)) == FAILURE)
			return (FAILURE);
		if (usleep(1) == FAILURE)
			return (FAILURE);
	}
}

int	release_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->fork_left->access)) == FAILURE)
		return (FAILURE);
	philo->fork_left->status = RELEASED;
	if (pthread_mutex_unlock(&(philo->fork_left->access)) == FAILURE)
		return (FAILURE);
	return (TRUE);
}

int	release_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->fork_right->access)) == FAILURE)
		return (FAILURE);
	philo->fork_right->status = RELEASED;
	if (pthread_mutex_unlock(&(philo->fork_right->access)) == FAILURE)
		return (FAILURE);
	return (TRUE);
}
