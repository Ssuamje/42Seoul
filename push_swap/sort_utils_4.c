/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:59:46 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 21:49:52 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_times(t_deque *a, t_deque *b, t_deque *cmd, int times)
{
	int	idx;

	idx = -1;
	while (++idx < times)
		pa(a, b, cmd);
}

void	pb_times(t_deque *a, t_deque *b, t_deque *cmd, int times)
{
	int	idx;

	idx = -1;
	while (++idx < times)
		pb(a, b, cmd);
}
