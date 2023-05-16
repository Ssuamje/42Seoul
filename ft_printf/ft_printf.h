/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:39:55 by sanan             #+#    #+#             */
/*   Updated: 2022/11/30 13:14:14 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define W_ERROR -1
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_by_specfier(va_list ap, char spcf, int *idx, int *len_p);
int	print_char(char c);
int	print_string(char *str);
int	print_decimal_integer(int di);
int	print_unsigned_int(unsigned int u);
int	print_pointer(void *ptr);
int	print_hex_lower(unsigned int to_convert);
int	print_hex_upper(unsigned int to_convert);
int	putnbr_decimal(int n, int *digit);
int	putnbr_base(unsigned long long nbr, char *base);

#endif