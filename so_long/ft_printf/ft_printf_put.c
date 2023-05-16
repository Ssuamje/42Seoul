/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:21:40 by sanan             #+#    #+#             */
/*   Updated: 2022/11/30 13:18:03 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	if (write(1, &c, 1) == W_ERROR)
		return (W_ERROR);
	return (1);
}

int	print_string(char *str)
{
	long	len;

	len = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == W_ERROR)
			return (W_ERROR);
		return (6);
	}
	while (str[len])
		len++;
	if (len - 1 > __INT_MAX__)
		return (W_ERROR);
	if (write(1, str, len) == W_ERROR)
		return (W_ERROR);
	return (len);
}

int	print_decimal_integer(int di)
{
	int	digit;

	digit = 0;
	if (di == -2147483648)
	{
		if (write(1, "-2147483648", 11) == W_ERROR)
			return (W_ERROR);
		return (11);
	}
	digit = putnbr_decimal(di, &digit);
	if (digit < 0 || digit > 11)
		return (W_ERROR);
	return (digit);
}

int	print_unsigned_int(unsigned int u)
{
	int	len_printed;

	len_printed = putnbr_base(u, "0123456789");
	return (len_printed);
}
