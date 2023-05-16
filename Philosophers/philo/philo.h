/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:29:04 by sanan             #+#    #+#             */
/*   Updated: 2023/03/06 15:12:22 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>

enum e_enums{
	FAILURE = -1,
	SYSTEM_SUCCESS = 0,
	FALSE = 0,
	THREAD_ERROR = 1,
	TRUE = 1,
};

enum e_quit{
	QUIT_ARGS = -10,
	QUIT_ATOI,
	QUIT_FORK,
	QUIT_TABLE,
	QUIT_INFO,
	QUIT_INFO_MUTEX,
	QUIT_PHILOS,
	QUIT_PHILO_EACH,
};

enum e_fork_status{
	HELD,
	RELEASED,
};

enum e_action_for_print{
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
};

typedef struct s_fork{
	int				status;
	pthread_mutex_t	access;
}	t_fork;

typedef struct s_info{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	uint64_t		count_to_eat;
	int				has_count_eat;
	pthread_mutex_t	megaphone;
	pthread_mutex_t	check_death;
	int				is_anyone_dead;
}	t_info;

typedef struct s_philo{
	pthread_t		id;
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				has_count_eat;
	uint64_t		count_to_eat;
	uint64_t		last_eat_time;
	uint64_t		start_time;
	t_fork			*fork_left;
	t_fork			*fork_right;
	pthread_mutex_t	*megaphone;
	pthread_mutex_t	*check_death;
	int				*is_anyone_dead;
}	t_philo;

typedef struct s_table{
	int				number_of_philo;
	t_fork			**forks;
	t_philo			**philos;
}	t_table;

/* ./frees.c */

int			free_forks(t_fork **forks, int number_of_philo);
int			free_philo_each(t_philo **philos, int stopped);
int			cleaning(t_table *table, t_info *info);
int			quit_program(int quit_flag, t_table *table, t_info *info);

/* ./init.c */

int			set_forks_on_table(t_table *table);
int			init_table(t_table **table, char **av);
int			inform_to_philo(t_philo *philo, t_info *info);
int			sit_philos(t_table *table, t_info *info);
int			set_info(t_info **info, char **av);

/* ./init_2.c */

int			is_args_valid(int ac, char **av);

/* ./parse.c */

int			ft_isdigit(char c);
int			philo_atoi(char *str);

/* ./philo.c */

int			death_conscious_act(t_philo *philo, uint64_t time_to_act);
int			take_forks(t_philo *philo);
int			eat_and_release_forks(t_philo *philo);
int			notice_dead_while_sleep(t_philo *philo);

/* ./utils_dead.c */

int			is_anyone_dead(t_philo *philo);
int			mark_death(t_philo *philo);
int			am_i_dead(t_philo *philo);
int			if_dead_notice_death(t_philo *philo);

/* ./utils_dining.c */

void		*routine(void *arg);
int			start_dinner_odd(t_table *table);
int			start_dinner_even(t_table *table);
int			wait_for_dinner_finished(t_table *table);
int			dining(t_table *table, t_info *info);

/* ./utils_fork.c */

int			try_to_hold_fork(t_fork *fork);
int			take_left_fork(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			release_left_fork(t_philo *philo);
int			release_right_fork(t_philo *philo);

/* ./utils_print.c */

void		print_by_flag(int quit_flag);
char		*msg(int status);
int			shout(t_philo *philo, int status);

/* ./utils_time.c */

uint64_t	get_time(void);
int			take_time(uint64_t ms);

#endif