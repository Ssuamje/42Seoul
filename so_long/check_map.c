/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:59:53 by sanan             #+#    #+#             */
/*   Updated: 2022/12/25 23:30:24 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_path(t_info *info)
{
	dfs_path(info->loc_player.y, info->loc_player.x, info);
	return (info->point_collect == info->dfs_collect && \
			info->point_escape == info->dfs_escape);
}

int	check_map_size(t_info *info)
{
	if ((info->col_map < 4 && info->row_map < 4) || \
		info->row_map > (H_RANGE / H_SIZE) || \
		info->col_map > (W_RANGE / W_SIZE))
		return (ERROR_SIZE);
	return (TRUE);
}

int	check_map_wall(t_info *info, int row)
{
	if (!is_surrounded(info->map[row]) || \
		!is_top_bottom(info->map[row], row, info))
		return (ERROR_WALL);
	return (TRUE);
}

int	check_map_format(t_info *info)
{
	int	row;
	int	col;

	row = -1;
	if (check_map_size(info) == ERROR_SIZE)
		return (print_error(ERROR_SIZE));
	while (info->map[++row] != NULL)
	{
		col = -1;
		while (info->map[row][++col] != '\0')
		{
			if (!is_charset(info->map[row][col], "01CPE"))
				return (print_error(ERROR_COMPONENT));
			catch_component(row, col, info);
		}
		if (check_map_wall(info, row) == ERROR_WALL)
			return (print_error(ERROR_WALL));
		if (col != info->col_map)
			return (print_error(ERROR_RECTANGULAR));
	}
	if (row != info->row_map)
		return (print_error(ERROR_RECTANGULAR));
	if (is_point_valid(info) == ERROR_POINT)
		return (print_error(ERROR_POINT));
	return (TRUE);
}
