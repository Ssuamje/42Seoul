/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:20:14 by sanan             #+#    #+#             */
/*   Updated: 2022/11/30 13:03:29 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	putnbr_decimal(int n, int *digit)
{
	char	c;

	if (n < 0)
	{
		if (write(1, "-", 1) == W_ERROR)
			return (W_ERROR);
		n *= -1;
		putnbr_decimal(n, digit);
		(*digit) += 1;
	}
	else if (n >= 10)
	{
		if (putnbr_decimal(n / 10, digit) == W_ERROR)
			return (W_ERROR);
		if (putnbr_decimal(n % 10, digit) == W_ERROR)
			return (W_ERROR);
	}
	else
	{
		c = n + '0';
		if (write(1, &c, 1) == W_ERROR)
			return (W_ERROR);
		(*digit) += 1;
	}
	return (*digit);
}
