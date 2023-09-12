/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:28:48 by sanan             #+#    #+#             */
/*   Updated: 2023/06/20 12:44:31 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_conscious_act(t_philo *philo, uint64_t time_to_act)
{
	uint64_t	now;
	uint64_t	time;
	int			dead;

	now = get_time();
	time = now;
	if (time == FALSE)
		return (FAILURE);
	while (time - now < time_to_act)
	{
		if (usleep(250) != SYSTEM_SUCCESS)
			return (FAILURE);
		dead = if_dead_notice_death(philo);
		if (dead == FAILURE)
			return (FAILURE);
		if (dead == TRUE)
			return (TRUE);
		time = get_time();
		if (time == FALSE)
			return (FAILURE);
	}
	return (FALSE);
}

int	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = take_left_fork(philo);
	if (left == FAILURE)
		return (FAILURE);
	right = take_right_fork(philo);
	if (right == FAILURE)
		return (FAILURE);
	if (left == FALSE || right == FALSE)
		return (FALSE);
	return (TRUE);
}

int	eat_and_release_forks(t_philo *philo)
{
	if (shout(philo, EATING) == FAILURE)
		return (FAILURE);
	philo->last_eat_time = get_time();
	if (philo->last_eat_time == FALSE)
		return (FAILURE);
	if (death_conscious_act(philo, philo->time_to_eat) == FAILURE)
		return (FAILURE);
	if (philo->has_count_eat == TRUE)
		(philo->count_to_eat)--;
	if (release_right_fork(philo) == FAILURE)
		return (FAILURE);
	if (release_left_fork(philo) == FAILURE)
		return (FAILURE);
	return (TRUE);
}

int	notice_dead_while_sleep(t_philo *philo)
{
	int	dead;

	if (shout(philo, SLEEPING) == FAILURE)
		return (FAILURE);
	dead = death_conscious_act(philo, philo->time_to_sleep);
	return (dead);
}

int	main(int ac, char **av)
{
	t_table	*table;
	t_info	*info;
	int		err;

	err = FALSE;
	table = NULL;
	info = NULL;
	err = is_args_valid(ac, av);
	if (err == QUIT_ARGS || err == QUIT_ATOI)
		return (quit_program(err, table, info));
	err = set_info(&info, av);
	if (err == QUIT_INFO || err == QUIT_INFO_MUTEX)
		return (quit_program(err, table, info));
	err = init_table(&table, av);
	if (err == QUIT_TABLE || err == QUIT_FORK)
		return (quit_program(err, table, info));
	err = sit_philos(table, info);
	if (err == QUIT_PHILOS || err == QUIT_PHILO_EACH || err == FAILURE)
		return (quit_program(err, table, info));
	dining(table, info);
	if (cleaning(table, info) == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
