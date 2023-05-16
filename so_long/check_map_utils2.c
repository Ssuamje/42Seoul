/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:00:29 by sanan             #+#    #+#             */
/*   Updated: 2022/12/25 22:37:15 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dest;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	dest = malloc(count * size);
	if (dest == 0)
		return (NULL);
	ft_memset(dest, 0, count * size);
	return (dest);
}

int	**make_visit_list(t_info *info)
{
	int	**visit_list;
	int	idx;

	visit_list = malloc(sizeof(int *) * info->row_map);
	if (!visit_list)
		return (NULL);
	idx = -1;
	while (++idx < info->row_map)
	{
		visit_list[idx] = ft_calloc(info->col_map, sizeof(int));
		if (!visit_list[idx])
			return (NULL);
	}
	return (visit_list);
}

void	set_move(t_move *move)
{
	move->dx[0] = 1;
	move->dx[1] = -1;
	move->dx[2] = 0;
	move->dx[3] = 0;
	move->dy[0] = 0;
	move->dy[1] = 0;
	move->dy[2] = 1;
	move->dy[3] = -1;
}

void	get_loc_player(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'P')
			{
				info->loc_player.x = j;
				info->loc_player.y = i;
			}
			j++;
		}
		i++;
	}
}

int	init_info(t_info *info)
{
	info->row_map = get_row(info->map);
	info->col_map = get_col(info->map[0]);
	info->point_collect = 0;
	info->point_escape = 0;
	info->point_start = 0;
	info->dfs_collect = 0;
	info->dfs_escape = 0;
	info->count_moves = 0;
	get_loc_player(info);
	info->visit_list = make_visit_list(info);
	if (info->visit_list == NULL)
		return (FALSE);
	set_move(&(info->move));
	return (TRUE);
}
