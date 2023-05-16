/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:53 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 22:09:42 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_idx(t_idx *info)
{
	info->idx_five = 0;
	info->idx_four = 0;
	info->idx_iter = 0;
	info->count_ra = 0;
	info->count_rb = 0;
}

void	sort_four_b(t_deque *a, t_deque *b, t_deque *cmd)
{
	push_four_b_to_a(a, b, cmd);
	sort_three_below_b(b, cmd, 3);
	pb(a, b, cmd);
}

void	sort_five_a_above(t_deque *a, t_deque *b, t_deque *cmd)
{
	push_five_four_a_to_b_above(a, b, cmd);
	sort_three_below_a_above(a, cmd);
	pa_times(a, b, cmd, 2);
}

void	sort_five_b_above(t_deque *a, t_deque *b, t_deque *cmd)
{
	push_five_four_b_to_a_above(a, b, cmd);
	sort_three_below_b_above(b, cmd);
	pb_times(a, b, cmd, 2);
}
