/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:20:08 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 08:10:20 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define FAILURE -1

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	philo_atoi(char *str)
{
	int		i;
	long	result;
	int		digit;
	int		sign;

	i = 0;
	result = 0;
	digit = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (!ft_isdigit(str[i]) \
	|| sign == -1)
		return (FAILURE);
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i++] - 48);
		digit++;
	}
	if (str[i] != '\0' || digit > 10 \
		|| result * sign < INT_MIN || result * sign > INT_MAX \
		|| result * sign == 0)
		return (FAILURE);
	return (result * sign);
}
