/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:45:14 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 22:29:23 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*is_split_ok(char *chunk)
{
	if (chunk == NULL || \
		chunk[0] == '\0' || \
		((chunk[0] == '+' || chunk[0] == '-') && chunk[1] == '\0'))
		return (NULL);
	else
		return (chunk);
}

void	free_split(char ***splitted)
{
	int	idx;

	idx = 0;
	while ((*splitted)[idx] != NULL)
	{
		free((*splitted)[idx]);
		(*splitted)[idx] = NULL;
		idx++;
	}
	free(*splitted);
	*splitted = NULL;
}

int	ft_pssw_atoi(char *str)
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
	if (!ft_isdigit(str[i]))
		error_exit(ERR_ATOI_INVALID_SPACE);
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i++] - 48);
		digit++;
	}
	if (str[i] != '\0')
		error_exit(ERR_ATOI_INVALID_SPACE);
	if (digit > 10 || result * sign < INT_MIN || result * sign > INT_MAX)
		error_exit(ERR_ATOI_OVERFLOW);
	return (result * sign);
}

int	is_str_only_white_spaces(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!((9 <= str[idx] && str[idx] <= 13) \
			|| str[idx] == 32))
			return (0);
		idx++;
	}
	return (1);
}
