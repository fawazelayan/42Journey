#include "philo.h"

void	parse_input(t_data *data, int ac, char **av)
{
	data -> ph_num  = ft_atol(av[0]);
	data -> tod = ft_atol(av[1]);
	data -> toe = ft_atol(av[2]);
	data -> tos = ft_atol(av[3]);
	data -> ml_num = -1;
	if (ac == 6)
		data -> ml_num = ft_atol(av[4]);
}

void	mutex_opers(t_mtx *mtx, t_code code)
{
	if (code == INIT)
		pthread_mutex_init(mtx, NULL);
	else if (code == LOCK)
		pthread_mutex_lock(mtx);
	else if (code == UNLOCK)
		pthread_mutex_unlock(mtx);
	else if (code == DESTROY)
		pthread_mutex_destroy(mtx);
	else
		return ;
}

void	thread_opers(t_thr *thr, void * (*foo)(void *), void *data, t_code cd)
{
	if (cd == CRT)
		pthread_create(thr, NULL, foo, data);
	else if (cd == JOIN)
		pthread_join(*thr, NULL);
	else if (cd == DETACH)
		pthread_detach(*thr);
	return ;
}

void	precise_usleep(t_data *data, long time)
{
	long	start;

	start = get_time_in_ms();
	if (sim_fin(data))
		return ;
	while (get_time_in_ms() - start < time)
	{
		if (get_bool(&data -> dat_lk, &data -> ended))
			break ;
		usleep(100);
	}
}

void	increase_long(t_mtx *mtx, long *val)
{
	mutex_opers(mtx, LOCK);
	(*val)++;
	mutex_opers(mtx, UNLOCK);
}
