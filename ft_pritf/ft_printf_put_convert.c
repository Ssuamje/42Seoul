/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:21:50 by sanan             #+#    #+#             */
/*   Updated: 2022/11/30 13:03:16 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int					len_printed;
	unsigned long long	ptr_cast;

	len_printed = 0;
	ptr_cast = (unsigned long long)ptr;
	if (ptr_cast == 0)
	{
		if (write(1, "0x0", 3) == W_ERROR)
			return (W_ERROR);
		return (3);
	}
	if (write(1, "0x", 2) == W_ERROR)
		return (W_ERROR);
	len_printed = putnbr_base(ptr_cast, "0123456789abcdef");
	if (len_printed == W_ERROR)
		return (W_ERROR);
	return (len_printed + 2);
}

int	print_hex_lower(unsigned int to_convert)
{
	int	len_printed;

	len_printed = putnbr_base(to_convert, "0123456789abcdef");
	return (len_printed);
}

int	print_hex_upper(unsigned int to_convert)
{
	int	len_printed;

	len_printed = putnbr_base(to_convert, "0123456789ABCDEF");
	return (len_printed);
}
