/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:04:30 by sanan             #+#    #+#             */
/*   Updated: 2022/11/28 20:17:10 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dest;

	if (n == 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin_free(char *s1, char *s2, size_t len_s2)
{
	size_t	len_s1;
	char	*result;

	if (s1 == NULL)
		return (ft_strndup(s2, len_s2));
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	result = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)s1, len_s1 + 1);
	if (len_s2 != 0)
		ft_strlcpy(&result[len_s1], (char *)s2, len_s2 + 1);
	free_str(&s1, NULL);
	return (result);
}

ssize_t	get_idx_nl(char *string, size_t len)
{
	ssize_t	idx;

	if (!string || len <= 0)
		return (-1);
	idx = 0;
	while ((size_t)idx < len && string[idx])
	{
		if (string[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*free_str(char **s1, char **s2)
{
	if (s1 != NULL)
	{
		if (*s1 != NULL)
		{
			free(*s1);
			*s1 = NULL;
		}
	}
	if (s2 != NULL)
	{
		if (*s2 != NULL)
		{
			free(*s2);
			*s2 = NULL;
		}
	}
	return (NULL);
}
