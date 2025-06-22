#include "philo.h"

int create_threads(t_data *dt)
{
    int	i;

	i = 0;
	if (dt -> ph_num == 1)
    {
		if(thr_ops(&dt -> philos[0].thr, im_mr_lonely,
			&dt -> philos[0], CRT))
            return (print_error_ret("philo thread failed to create", 1));
    }
    else
    {
		while (i < dt -> ph_num)
		{
			if (thr_ops(&dt ->philos[i].thr, dine_in, &dt -> philos[i], CRT))
                return (print_error_ret("philos threads failed to create", 1));
			i++;
		}
	}
    if (thr_ops(&dt -> monitor, monitoring, dt, CRT))
        return (print_error_ret("monitor thread faile to create", 1));
    return (0);
}

int join_threads(t_data *dt)
{
    int i;

    i = 0;
    while (i < dt -> ph_num)
    {
        if (thr_ops(&dt -> philos[i++].thr, NULL, NULL, JOIN))
            return (print_error_ret("philos threads failed to join", 1));
    }
    return (0);
}
