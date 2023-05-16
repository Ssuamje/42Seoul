/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:50:52 by sanan             #+#    #+#             */
/*   Updated: 2022/11/30 13:03:28 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	count(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	put_converted(unsigned long long nbr, int *result, char *base)
{
	int	i;
	int	digit;
	int	len_put;

	i = 0;
	digit = count(base);
	if (nbr == 0)
	{
		if (write(1, &base[0], 1) == W_ERROR)
			return (W_ERROR);
		return (1);
	}
	while (nbr > 0)
	{
		result[i++] = nbr % digit;
		nbr /= digit;
	}
	len_put = i;
	while (--i >= 0)
	{
		if (write(1, &base[result[i]], 1) == W_ERROR)
			return (W_ERROR);
	}
	return (len_put);
}

int	putnbr_base(unsigned long long nbr, char *base)
{
	int	result[32];
	int	len_put;

	if (base[0] == '\0' || base[1] == '\0' || check(base) == 0)
		return (-1);
	len_put = put_converted(nbr, result, base);
	return (len_put);
}
