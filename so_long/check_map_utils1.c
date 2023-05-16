/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:26:00 by sanan             #+#    #+#             */
/*   Updated: 2022/12/26 14:28:19 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_top_bottom(char *row, int len, t_info *info)
{
	int	col;

	if (len != 0 || len != info->row_map)
		return (TRUE);
	col = 0;
	while (row[col] != '\n' && row[col] != '\0')
	{
		if (row[col] != '1')
			return (FALSE);
		col++;
	}
	if (row[col] != '1')
		return (FALSE);
	return (TRUE);
}

int	is_surrounded(char *row)
{
	int	col;

	col = 0;
	if (row[col] != '1')
		return (FALSE);
	while (row[col] != '\n' && row[col] != '\0')
		col++;
	if (row[col - 1] != '1')
		return (FALSE);
	return (TRUE);
}

int	is_charset(char c, char *charset)
{
	int	i;

	if (c == '\n')
		return (TRUE);
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	get_col(char *row)
{
	int	col;

	col = 0;
	while (row[col] != '\0')
		col++;
	return (col);
}

int	get_row(char **map)
{
	int	row;

	row = 0;
	while (map[row] != NULL)
		row++;
	return (row);
}
