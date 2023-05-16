/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:50:44 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 07:56:23 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_args_valid(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (QUIT_ARGS);
	if (philo_atoi(av[1]) <= 0 \
	|| philo_atoi(av[2]) <= 0 \
	|| philo_atoi(av[3]) <= 0 \
	|| philo_atoi(av[4]) <= 0 \
	|| (ac == 6 && philo_atoi(av[5]) <= 0))
		return (QUIT_ATOI);
	return (TRUE);
}
