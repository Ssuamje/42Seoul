/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:51 by sanan             #+#    #+#             */
/*   Updated: 2022/12/24 20:59:17 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs_catch_component(int row, int col, t_info *info)
{
	if (info->map[row][col] == 'C')
		(info->dfs_collect)++;
	if (info->map[row][col] == 'E')
		(info->dfs_escape)++;
}

void	dfs_path(int y, int x, t_info *info)
{
	t_loc	next;
	int		i;

	dfs_catch_component(y, x, info);
	(info->visit_list)[y][x] = 1;
	if (info->map[y][x] == 'E')
		return ;
	i = -1;
	while (++i < 4)
	{
		next.x = x + (info->move).dx[i];
		next.y = y + (info->move).dy[i];
		if ((next.x < info->col_map && next.y < info->row_map) && \
			(next.x > 0 && next.y > 0) && \
			info->map[next.y][next.x] != '1' && \
			(info->visit_list)[next.y][next.x] == 0)
			dfs_path(next.y, next.x, info);
	}
}
