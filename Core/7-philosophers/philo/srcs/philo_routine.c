#include "philo.h"

// void    is_thinking(t_philo *philo)
// {

// }

void    is_eating(t_philo *ph)
{
    long    stamp;

    stamp = get_time_in_ms() - ph -> table -> st;
}

void    is_sleeping(t_philo *philo)
{
    long stamp;

    stamp = get_time_in_ms() - philo -> table -> st;
    printf(PRP"%ld  Philo %d is sleeping.\n"RST, stamp, philo -> id);
    usleep(philo -> table -> tos * 1000);
}

// void    take_fork(t_philo *philo)
// {

// }

void is_dead(t_philo *philo)
{
    long    last_meal;

    pthread_mutex_lock(&philo->table-> eat_lk);
    last_meal = philo->lmt;
    pthread_mutex_unlock(&philo->table-> eat_lk);
    if (get_time_in_ms() - last_meal > philo -> table -> tod)
    {
        pthread_mutex_lock(&philo -> table -> end_lk);
        philo -> table -> ended = 1;
        printf(RED"Philo %d has died.\n"RST, philo -> id);
        pthread_mutex_unlock(&philo -> table -> end_lk);
    }
}
