#include "philo.h"

void	*start_sim(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo -> table -> ended)
		return (NULL);
	usleep(10000);
	philo -> table -> ended = 1;
	return (NULL);
}
