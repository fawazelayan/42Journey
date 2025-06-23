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

/*  ========================  */
/*		   DEFINITIONS		  */
/*  ========================  */
#ifndef PHILO_H
# define PHILO_H

# define CYN	"\033[0;36m"
# define PRP	"\033[0;35m"
# define YLW	"\033[0;33m"
# define GRN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

/*  ========================  */
/*			INCLUDES		  */
/*  ========================  */
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread functions
# include <string.h>	// memset
# include <unistd.h>	// usleep, write
# include <stdlib.h>	// malloc, free
# include <stdio.h>		// printf
# include <limits.h>	// INT_MAX
# include <stdbool.h>	// bool type

/*  ========================  */
/*		STRUCTS & ENUMS		  */
/*  ========================  */
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
	JOIN
}	t_code;

typedef struct s_fork
{
	t_mtx	mutex;	// mutex for each fork to use locks
	int		id;		// id for each fork
}	t_fork;

typedef struct s_philo
{
	t_data		*table;	// each philo gets access to data (global data)
	t_fork		*first;	// right fork
	t_mtx		eat_lk;	// lock to read and write lmt
	t_fork		*scnd;	// left fork
	t_thr		thr;	// thread for each philo
	bool		full;	// full flag
	long		ml_cnt;	// meal counter
	long		lmt;	// last_meal_time
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

/*  ========================  */
/*		VALIDATION FUNCS	  */
/*  ========================  */
bool	is_valid_prog(int ac, char **av);

/*  ========================  */
/*		  UTILS FUNCS		  */
/*  ========================  */
int		thr_ops(t_thr *thr, void *(*foo)(void *), void *data, t_code cd);
int		print_action(t_philo *ph, t_ph_status st);
int		print_error_ret(char *error, int ret);
int		mutex_opers(t_mtx *mtx, t_code code);
int		create_threads(t_data *dt);
int		join_threads(t_data *dt);
int		str_len(char *str);
bool	threads_active(t_mtx *mtx, long *th, long ph_num);
bool	get_bool(t_mtx *mtx, bool *val);
bool	sim_fin(t_data *data);
void	parse_input(t_data *data, int ac, char **av);
void	set_bool(t_mtx *mtx, bool *set, bool val);
void	set_long(t_mtx *mtx, long *set, long val);
void	precise_usleep(t_data *data, long time);
void	increase_long(t_mtx *mtx, long *val);
void	wait_threads(t_data *dt);
void	de_synchro(t_philo *ph);
long	get_long(t_mtx *mtx, long *val);
long	ft_atol(char *str);
long	get_time_in_ms(void);
void	*monitoring(void *data);

/*  ========================  */
/*		  INIT FUNCS		  */
/*  ========================  */
int		init_data(t_data *data, int ac, char **av);


/*  ========================  */
/*		SIMULATION FUNCS	  */
/*  ========================  */
int		think(t_philo *ph, bool in_dinner);
int		start_sim(t_data *data);
void	*im_mr_lonely(void *data);
void	*dine_in(void *philo);

/*  ========================  */
/*		CLEANING FUNCS		  */
/*  ========================  */
int		clean_sim(t_data *data);

#endif