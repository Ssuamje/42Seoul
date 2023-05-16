/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:26:48 by sanan             #+#    #+#             */
/*   Updated: 2022/12/26 14:28:02 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_ptrs *ptrs, char *dir)
{
	ptrs->info = malloc(sizeof(t_info));
	if (ptrs->info == NULL)
		return (print_error(EXIT_ERROR));
	ptrs->info->map = get_map(dir);
	if (ptrs->info->map == NULL)
		return (print_error(ERROR_MAP));
	if (!init_info(ptrs->info))
		return (print_error(ERROR_INIT));
	if (check_map_format(ptrs->info) != 1)
		return (EXIT_ERROR);
	if (check_map_path(ptrs->info) != 1)
		return (print_error(ERROR_INVALID_MAP));
	return (TRUE);
}

void	put_image(t_ptrs *ptrs, void *img_ptr, int x_loc, int y_loc)
{
	mlx_put_image_to_window(ptrs->mlx, ptrs->window, \
							img_ptr, x_loc, y_loc);
}

void	render_map(t_ptrs *ptrs)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ptrs->info->row_map)
	{
		j = -1;
		while (++j < ptrs->info->col_map)
		{
			if ((ptrs->info->map)[i][j] == '1')
				put_image(ptrs, ptrs->img_wall, j * W_SIZE, i * H_SIZE);
			if ((ptrs->info->map)[i][j] == '0')
				put_image(ptrs, ptrs->img_empty, j * W_SIZE, i * H_SIZE);
			if ((ptrs->info->map)[i][j] == 'E')
				put_image(ptrs, ptrs->img_escape, j * W_SIZE, i * H_SIZE);
			if ((ptrs->info->map)[i][j] == 'P')
				put_image(ptrs, ptrs->img_player, j * W_SIZE, i * H_SIZE);
			if ((ptrs->info->map)[i][j] == 'C')
				put_image(ptrs, ptrs->img_collect, j * W_SIZE, i * H_SIZE);
		}
	}
}

int	init_game(t_ptrs *ptrs, char *dir)
{
	int	dump;

	if (check_map(ptrs, dir) == EXIT_ERROR)
		return (EXIT_ERROR);
	ptrs->mlx = mlx_init();
	ptrs->window = mlx_new_window(ptrs->mlx, \
					(ptrs->info->col_map) * W_SIZE, \
					(ptrs->info->row_map) * H_SIZE, \
					"so_long");
	ptrs->img_collect = mlx_xpm_file_to_image(ptrs->mlx, \
						"./textures/collect.xpm", &dump, &dump);
	ptrs->img_empty = mlx_xpm_file_to_image(ptrs->mlx, \
						"./textures/empty.xpm", &dump, &dump);
	ptrs->img_escape = mlx_xpm_file_to_image(ptrs->mlx, \
						"./textures/escape.xpm", &dump, &dump);
	ptrs->img_player = mlx_xpm_file_to_image(ptrs->mlx, \
						"./textures/player.xpm", &dump, &dump);
	ptrs->img_wall = mlx_xpm_file_to_image(ptrs->mlx, \
						"./textures/wall.xpm", &dump, &dump);
	render_map(ptrs);
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	ptrs;

	if (ac != 2)
		return (print_error(EXIT_ERROR));
	if (init_game(&ptrs, av[1]) == EXIT_ERROR)
		clear_and_exit(&ptrs, 0);
	mlx_key_hook(ptrs.window, get_key, &ptrs);
	mlx_hook(ptrs.window, 17, 1L << 2, clear_and_exit, &ptrs);
	mlx_loop(ptrs.mlx);
	return (0);
}
