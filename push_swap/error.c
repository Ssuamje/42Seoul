/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:29:03 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 10:04:06 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(char *message)
{
	ft_putstr_fd(message, 2);
}

void	error_exit(int error_code)
{
	if (error_code == ERR_ARGUMENT_COUNTS)
		write_error("Error\nStatement : Argument count is invalid.\n");
	if (error_code == ERR_ARGUMENT_EMPTY)
		write_error("Error\nStatement : Argumet is empty.\n");
	if (error_code == ERR_ALLOC)
		write_error("Error\nStatement : Memory allocation failed.\n");
	if (error_code == ERR_SPLIT_CHUNK)
		write_error("Error\nStatement : Invalid argument detected.\n");
	if (error_code == ERR_ATOI_OVERFLOW)
		write_error("Error\nStatement : Digit of argument overflows INT_MAX.\n");
	if (error_code == ERR_ATOI_INVALID_SPACE)
		write_error("Error\nStatement : Wrong character detected in argument.\n");
	if (error_code == ERR_DEQ)
		write_error("Error\nStatement : Deque creating malfunction occured.\n");
	if (error_code == ERR_LIST)
		write_error("Error\nStatement : List malfunction while parsing.\n");
	if (error_code == ERR_VALUE_DUPLICATED)
		write_error("Error\nStatement : Duplicated argument detected.\n");
	exit(EXIT_FAILURE);
}
