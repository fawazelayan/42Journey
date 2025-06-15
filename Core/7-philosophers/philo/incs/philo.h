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

# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread functions
# include <string.h> // memset
# include <unistd.h> // usleep, write
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <limits.h> // LONG_MAX

# define PRP	"\033[0;35m"
# define YLW	"\033[0;33m"
# define GRN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RST	"\033[0m"

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				id;
}	t_fork;

typedef struct s_philo
{
	long		lmt;	// last_meal_time
	long		meal_cntr;
	t_fork		*right;
	t_fork		*left;
	t_data		*table;
	pthread_t	thread;
	int			full;
	int			id;

}	t_philo;

struct s_data
{
	long	tod;	// time_to_die
	long	toe;	// time_to_eat
	long	tos;	// time_to_sleep
	long	philos_num;
	long	meals_num;
	long	st;		// start_time
	long	et;		// end_time
	int		ended;	// death or all philos are full
	pthread_mutex_t	eat_lk;
	pthread_mutex_t	end_lk;
	pthread_mutex_t prt_lk;
	t_philo	*philos;
	t_fork	*forks;
};

int		validation(int ac, char **av);
int		invalid_args(char **args);
int		ft_isnumber(char *str);
int		ft_isempty(char *str);

void	print_error(char *error);
int		ft_strlen(char *str);
long	ft_atol(char *str);

void	*start_sim(void *ph);

int		init_data(t_data *data, int ac, char **av);
int		init_philos(t_data *data);
int		init_locks(t_data *data);
int		init_forks(t_data *data);

void	detach_thread(t_philo *philos, int cnt);
void	join_thread(t_philo *philos, int cnt);
void	destroy_mutex(t_fork *forks, int cnt);
int		clean_sim(t_data *data, int cnt);

long	get_time_in_ms(void);

void    is_eating(t_philo *philo);
void    is_sleeping(t_philo *philo);
void	is_dead(t_philo *philo);

#endif