/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:43:45 by sanan             #+#    #+#             */
/*   Updated: 2023/01/03 11:17:38 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dest;

	if (size && count > SIZE_MAX / size)
		return (0);
	dest = malloc(count * size);
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, 0, count * size);
	return ((void *)dest);
}
