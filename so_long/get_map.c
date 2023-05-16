/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:04:02 by sanan             #+#    #+#             */
/*   Updated: 2022/12/26 14:17:13 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	check_extension(char *dir)
{
	int	len;

	len = get_col(dir);
	if (len < 5)
		return (FALSE);
	if (dir[len - 4] == '.' && \
		dir[len - 3] == 'b' && \
		dir[len - 2] == 'e' && \
		dir[len - 1] == 'r')
		return (TRUE);
	else
		return (FALSE);
}

char	**get_map(char *dir)
{
	int		fd;
	char	**map;
	char	*row_read;
	int		row;

	fd = open(dir, O_RDONLY);
	if (fd < 0 || check_extension(dir) == FALSE)
		return (NULL);
	row_read = malloc(sizeof(char) * ((W_RANGE / W_SIZE)));
	map = malloc(sizeof(char *) * ((H_RANGE / H_SIZE) + 1));
	row = 0;
	row_read = get_next_line(fd);
	if (row_read == NULL)
		return (NULL);
	while (row_read != NULL && row < (H_RANGE / H_SIZE))
	{
		map[row] = ft_strdup(row_read);
		row++;
		row_read = get_next_line(fd);
	}
	if (row_read != NULL)
		return (NULL);
	map[row] = NULL;
	return (map);
}
