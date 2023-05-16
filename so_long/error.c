/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:34:26 by sanan             #+#    #+#             */
/*   Updated: 2022/12/25 22:37:26 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_info(t_info *info)
{
	int	i;

	i = 0;
	if (info->map == NULL)
		return ;
	while (i < info->row_map)
	{
		free((info->map)[i]);
		(info->map)[i] = NULL;
		free((info->visit_list)[i]);
		(info->visit_list)[i] = NULL;
		i++;
	}
	free(info->map);
	info->map = NULL;
	free(info->visit_list);
	info->visit_list = NULL;
	free(info);
}

int	print_error(int error_code)
{
	if (error_code == EXIT_ERROR)
		ft_printf("Executing Error : The application or argument is invalid.\n");
	if (error_code == ERROR_SIZE)
		ft_printf("Map Size Error : Map size is not proper.\n");
	if (error_code == ERROR_COMPONENT)
		ft_printf("Map Component Error : Components are not fully correct.\n");
	if (error_code == ERROR_WALL)
		ft_printf("Map Wall Error : Map is not surrounded correctly.\n");
	if (error_code == ERROR_RECTANGULAR)
		ft_printf("Map Rectangular Error : Map is not rectangular.\n");
	if (error_code == ERROR_INIT)
		ft_printf("Info Error : Failed to get info of game properly.\n");
	if (error_code == ERROR_POINT)
		ft_printf("Map Point Error : Map has not correct points.\n");
	if (error_code == ERROR_INVALID_MAP)
		ft_printf("Map Invalid Error : The path of map is invalid.\n");
	if (error_code == ERROR_MAP)
		ft_printf("Map Error : Map file is invalid.\n");
	ft_printf("Error\n");
	return (EXIT_ERROR);
}
