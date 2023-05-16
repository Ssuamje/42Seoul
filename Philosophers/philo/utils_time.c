/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:32:28 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 07:54:31 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != SYSTEM_SUCCESS)
		return (FALSE);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	take_time(uint64_t ms)
{
	uint64_t	now;

	now = get_time();
	while (get_time() - now < ms)
		if (usleep(250) != SYSTEM_SUCCESS)
			return (FAILURE);
	return (TRUE);
}
