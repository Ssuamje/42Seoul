/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:07:37 by sanan             #+#    #+#             */
/*   Updated: 2022/12/25 22:37:21 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_point_valid(t_info *info)
{
	if ((info->point_collect < 1) || \
		(info->point_escape != 1) || \
		(info->point_start != 1))
		return (ERROR_POINT);
	return (TRUE);
}

void	catch_component(int row, int col, t_info *info)
{
	if (info->map[row][col] == 'P')
		(info->point_start)++;
	if (info->map[row][col] == 'C')
		(info->point_collect)++;
	if (info->map[row][col] == 'E')
		(info->point_escape)++;
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = b;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return ((void *)dest);
}
