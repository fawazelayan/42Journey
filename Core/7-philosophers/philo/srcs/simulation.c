#include "philo.h"

void	*start_sim(void *ph)
{
	t_philo	*philo;
	long	elapsed_time;

	philo = (t_philo *)ph;
	elapsed_time = get_time_in_ms() - philo -> table -> start_time;
	if (philo -> table -> ended)
		return (NULL);
	while (!philo -> table -> ended)
	{
		//philo_take
		is_eating(philo);
		is_sleeping(philo);
		is_dead(philo);
	}
	return (NULL);
}
