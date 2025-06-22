/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:55:47 by felayan           #+#    #+#             */
/*   Updated: 2025/05/27 20:55:54 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define CYN	"\033[0;36m"
# define PRP	"\033[0;35m"
# define YLW	"\033[0;33m"
# define GRN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread functions
# include <string.h>	// memset
# include <unistd.h>	// usleep, write
# include <stdlib.h>	// malloc, free
# include <stdio.h>		// printf
# include <limits.h>	// LONG_MAX
# include <stdbool.h>	// bool type
# include <errno.h>		// error checking for pthread functions

typedef struct s_data	t_data;
typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_thr;

typedef enum e_ph_status
{
	TAKEN_FST,
	TAKE_SEC,
	SLEEP,
	THINK,
	DEAD,
	EAT
}	t_ph_status;

typedef enum e_code
{
	DESTROY,
	UNLOCK,
	LOCK,
	INIT,
	CRT,
	JOIN,
	DETACH
}	t_code;

typedef struct s_fork
{
	t_mtx	mutex;	// mutex for each fork to use locks
	int		id;		// id for each fork
}	t_fork;

typedef struct s_philo
{
	long		ml_cnt;	// meal counter
	long		lmt;	// last_meal_time
	t_thr	thread;	// thread for each philo
	t_data		*table;	// each philo gets access to data (global data)
	t_fork		*first;	// right fork
	t_fork		*scnd;	// left fork
	t_mtx		eat_lk;	// lock to read and write lmt
	bool		full;	// full flag
	int			id;		// id for each philo
}	t_philo;

struct s_data
{
	t_philo			*philos;	// philos array
	t_thr			monitor;		// death monitor
	t_fork			*forks;		// forks array
	t_mtx			dat_lk;		// data lock to read and write
	t_mtx			prt_lk;		// print locks to not overlap actions
	long			ml_num;		// meals num
	long			ph_num;		// philos num
	long			th_up;		// how many threads are running
	long			tod;		// time_to_die
	long			toe;		// time_to_eat
	long			tos;		// time_to_sleep
	long			st;			// start_time
	long			et;			// end_time
	bool			ended;		// death or all philos are full
	bool			wait;
};

// static bool	is_empty(char *str);
// static bool	is_num(char *str);
// static bool	invalid_args(char **args);
bool	is_valid_prog(int ac, char **av);

void	print_error(char *error);
void	print_action(t_philo *ph, t_ph_status st);
int		str_len(char *str);
long	ft_atol(char *str);
long	get_time_in_ms(void);
void	parse_input(t_data *data, int ac, char **av);
void	mutex_opers(t_mtx *mtx, t_code code);
void	thread_opers(t_thr *thr, void * (*foo)(void *), void *data, t_code cd);
void	precise_usleep(t_data *data, long time);
void	increase_long(t_mtx *mtx, long *val);

// static bool is_dead(t_philo *ph);
void	wait_threads(t_data *dt);
bool	threads_active(t_mtx *mtx, long *th, long ph_num);
void	*monitoring(void *data);
void	de_synchro(t_philo *ph);

// static void	assign_forks(t_philo *philo, t_fork *fork, int pos);
// static void	init_philo(t_data *data);
int		init_data(t_data *data, int ac, char **av);

void	set_bool(t_mtx *mtx, bool *set, bool val);
bool	get_bool(t_mtx *mtx, bool *val);
void	set_long(t_mtx *mtx, long *set, long val);
long	get_long(t_mtx *mtx, long *val);
bool	sim_fin(t_data *data);

// static void	eat(t_philo *ph);
void	*im_mr_lonely(void *data);
void	think(t_philo *ph, bool in_dinner);
void	*start_dinner(void *philo);
void	start_sim(t_data *data);

void	clean_sim(t_data *data);
#endif