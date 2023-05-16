/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:04:10 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:45:41 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*init_str(size_t size)
{
	char	*str;
	size_t	idx;

	str = malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		str[idx] = 0;
		idx++;
	}
	return (str);
}

char	*read_paste_till_last(int fd, char **buf, char **output, ssize_t *rd)
{
	*rd = read(fd, *buf, BUFFER_SIZE);
	while (*rd == BUFFER_SIZE && get_idx_nl(*buf, BUFFER_SIZE) == -1)
	{
		*output = ft_strjoin_free(*output, *buf, *rd);
		*rd = read(fd, *buf, BUFFER_SIZE);
	}
	if (*rd == -1)
		return (free_str(buf, output));
	return (*output);
}

char	*parse_last(char **left, char **buf, char **output, ssize_t *rd)
{
	ssize_t	idx_nl;
	char	*tmp;

	if (*rd == -1)
	{
		free_str(buf, output);
		return (free_str(left, NULL));
	}
	idx_nl = get_idx_nl(*buf, *rd);
	if (idx_nl != -1)
	{
		tmp = ft_strndup(*buf, (idx_nl + 1));
		*output = ft_strjoin_free(*output, tmp, (idx_nl + 1));
		(*left) = ft_strndup(&((*buf)[idx_nl + 1]), (*rd - (idx_nl + 1)));
	}
	else
	{
		if (*output == NULL && (*rd == 0 || *rd == -1))
			return (free_str(buf, NULL));
		tmp = ft_strndup(*buf, *rd);
		*output = ft_strjoin_free(*output, tmp, *rd);
	}
	free_str(buf, &tmp);
	return (*output);
}

char	*set_output_left(char **left, char **buf, ssize_t *rd, int fd)
{
	ssize_t	len_left;
	ssize_t	idx_nl;
	char	*output;
	char	*tmp;

	output = NULL;
	len_left = 0;
	while ((*left)[len_left])
		len_left++;
	idx_nl = get_idx_nl(*left, len_left);
	if (idx_nl != -1)
	{
		output = ft_strndup((*left), (idx_nl + 1));
		tmp = ft_strndup(&((*left)[idx_nl + 1]), (len_left - (idx_nl + 1)));
		free_str(left, buf);
		*left = tmp;
		return (output);
	}
	else
	{
		output = ft_strjoin_free(output, *left, len_left);
		free_str(left, NULL);
		output = read_paste_till_last(fd, buf, &output, rd);
		return (parse_last(&(*left), buf, &output, rd));
	}
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buf;
	char		*output;
	ssize_t		rd;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	output = NULL;
	buf = init_str(BUFFER_SIZE);
	if (buf == NULL)
		return (free_str(&buf, NULL));
	if (left[fd])
		return (set_output_left(&(left[fd]), &buf, &rd, fd));
	else
	{
		output = read_paste_till_last(fd, &buf, &output, &rd);
		return (parse_last(&(left[fd]), &buf, &output, &rd));
	}
}
