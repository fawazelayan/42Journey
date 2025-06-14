#include "philo.h"

void	clean_mutex(t_fork *forks, int cnt)
{
	int	i;

	i = 0;
	if (!forks)
		return ;
	while (i < cnt)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	free(forks);
}
