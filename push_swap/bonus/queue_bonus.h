/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:01:13 by sanan             #+#    #+#             */
/*   Updated: 2023/01/05 12:35:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_BONUS_H
# define QUEUE_BONUS_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_dlist{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_deque{
	struct s_dlist	*front;
	struct s_dlist	*rear;
	int				size;
}	t_deque;

enum	e_pop_return{
	POP_RETURN_PREV,
	POP_RETURN_NEXT
};

t_dlist	*new_dlist(int content);
void	delone_dlist(t_dlist **to_del);
t_deque	*init_deque(void);
void	push_left(t_dlist *node_to_push, t_deque *deq);
void	push_right(t_dlist *node_to_push, t_deque *deq);
void	pop_left(t_deque *deq);
void	pop_right(t_deque *deq);
t_dlist	*pop_node(t_deque *deq, t_dlist *node, int to_return);
void	sa(t_deque *a, t_deque *cmd);
void	sb(t_deque *b, t_deque *cmd);
void	ss(t_deque *a, t_deque *b, t_deque *cmd);
void	pa(t_deque *a, t_deque *b, t_deque *cmd);
void	pb(t_deque *a, t_deque *b, t_deque *cmd);
void	ra(t_deque *a, t_deque *cmd);
void	rb(t_deque *b, t_deque *cmd, int is_chained);
void	rr(t_deque *a, t_deque *b, t_deque *cmd);
void	rra(t_deque *a, t_deque *cmd);
void	rrb(t_deque *b, t_deque *cmd, int is_chained);
void	rrr(t_deque *a, t_deque *b, t_deque *cmd);
#endif