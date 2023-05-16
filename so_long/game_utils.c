/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:24:13 by sanan             #+#    #+#             */
/*   Updated: 2022/12/25 22:37:32 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_clear(t_ptrs *ptrs)
{
	ft_printf("Sonny Won The World Cup!\n");
	clear_and_exit(ptrs, 1);
}

void	update_player_loc(t_ptrs *ptrs, int dx, int dy)
{
	char	**map;
	int		x;
	int		y;

	x = ptrs->info->loc_player.x;
	y = ptrs->info->loc_player.y;
	map = ptrs->info->map;
	if (map[y + dy][x + dx] == '1')
		return ;
	else
	{
		if (map[y + dy][x + dx] == 'C')
			ptrs->info->point_collect -= 1;
		if (map[y + dy][x + dx] == 'E' && ptrs->info->point_collect != 0)
			return ;
		if (map[y + dy][x + dx] == 'E' && ptrs->info->point_collect == 0)
			game_clear(ptrs);
		ptrs->info->map[y][x] = '0';
		ptrs->info->map[y + dy][x + dx] = 'P';
		ptrs->info->loc_player.x += dx;
		ptrs->info->loc_player.y += dy;
		(ptrs->info->count_moves)++;
		ft_printf("count moves = %d\n", ptrs->info->count_moves);
	}
}

void	clear_img(t_ptrs *ptrs)
{
	free(ptrs->img_collect);
	free(ptrs->img_empty);
	free(ptrs->img_player);
	free(ptrs->img_wall);
	free(ptrs->img_escape);
}

int	clear_and_exit(t_ptrs *ptrs, int flag)
{
	clear_info(ptrs->info);
	if (flag == 1)
	{
		clear_img(ptrs);
		mlx_destroy_window(ptrs->mlx, ptrs->window);
	}
	exit(0);
}

int	get_key(int keycode, t_ptrs *ptrs)
{
	if (keycode == KEY_ESC)
		clear_and_exit(ptrs, 1);
	if (keycode == KEY_W)
		update_player_loc(ptrs, 0, -1);
	if (keycode == KEY_A)
		update_player_loc(ptrs, -1, 0);
	if (keycode == KEY_S)
		update_player_loc(ptrs, 0, 1);
	if (keycode == KEY_D)
		update_player_loc(ptrs, 1, 0);
	render_map(ptrs);
	return (0);
}
