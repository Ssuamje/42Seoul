/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:38:49 by sanan             #+#    #+#             */
/*   Updated: 2022/12/22 23:35:02 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_by_specfier(va_list ap, char spcf, int *idx, int *len_p)
{
	int	len_added;

	len_added = 0;
	if (spcf == 'c')
		len_added = print_char(va_arg(ap, int));
	else if (spcf == 's')
		len_added = print_string(va_arg(ap, char *));
	else if (spcf == 'd' || spcf == 'i')
		len_added = print_decimal_integer(va_arg(ap, int));
	else if (spcf == '%')
		len_added = print_char('%');
	else if (spcf == 'p')
		len_added = print_pointer(va_arg(ap, void *));
	else if (spcf == 'u')
		len_added = print_unsigned_int(va_arg(ap, unsigned int));
	else if (spcf == 'x')
		len_added = print_hex_lower(va_arg(ap, unsigned int));
	else if (spcf == 'X')
		len_added = print_hex_upper(va_arg(ap, unsigned int));
	(*len_p) += len_added;
	(*idx) += 2;
	if (len_added <= W_ERROR || *len_p < 0)
		return (W_ERROR);
	else
		return (1);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		len_p;
	int		idx;

	idx = 0;
	len_p = 0;
	va_start(ap, f);
	while (f[idx] && (0 <= len_p) && (len_p <= INT32_MAX))
	{
		if (f[idx] != '%')
		{
			if (print_char(f[idx++]) == W_ERROR)
				return (W_ERROR);
			len_p++;
		}
		else
			if (print_by_specfier(ap, f[idx + 1], &idx, &len_p) == W_ERROR)
				return (W_ERROR);
	}
	if (len_p < 0)
		return (W_ERROR);
	va_end(ap);
	return (len_p);
}
