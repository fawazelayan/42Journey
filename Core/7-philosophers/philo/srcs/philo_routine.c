#include "philo.h"

// void    is_thinking(t_philo *ph)
// {

// }

void    is_eating(t_philo *ph)
{
    long    stamp;

    stamp = get_time_in_ms() - ph -> table -> st;
    print_action(ph, stamp, "is eating");
    pthread_mutex_lock(&ph -> table -> eat_lk);
    ph -> lmt = get_time_in_ms();
    pthread_mutex_unlock(&ph -> table -> eat_lk);
    usleep(ph -> table -> toe * 1000);
}

void    is_sleeping(t_philo *ph)
{
    long stamp;

    stamp = get_time_in_ms() - ph -> table -> st;
    print_action(ph, stamp, "is sleeping");
    usleep(ph -> table -> tos * 1000);
}

// void    take_fork(t_philo *philo)
// {

// }

void *is_dead(t_data *data)
{
    int i;

    i = 0;
    while (i < data -> philos_num)
    {
        if (get_time_in_ms() - data -> philos[i].lmt > data -> tod)
        {
            pthread_mutex_lock(&data -> end_lk);
            data -> ended = 1;
            data -> et = get_time_in_ms() - data -> st;
            print_action(&data -> philos[i], data -> et, "has died");
            pthread_mutex_unlock(&data -> end_lk);
            return (NULL);
        }
    }
    return (NULL);
}
