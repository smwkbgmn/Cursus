/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_timer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:53:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/01 19:25:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

#include "philo.h"

void	check_death(t_list *data, t_msec *last_meal, t_msec die);

void	*timer(void *arg)
{
	t_list	*data;

	data = arg;
	check_death(data, &data->philo->info.time_last_meal,
		data->share->config.time_die);
	return (NULL);
}

void	check_death(t_list *data, t_msec *last_meal, t_msec die)
{
	while (LOOP && data)
	{
		if (get_time_elapsed(data, last_meal) > die)
		{
			print_death(data);
			semaphore(data, DEATH, OUT);
			break ;
		}
		else
			suspend(data, 10);
	}
}

void	start_timer(t_list *data)
{
	set_time(data, &data->philo->info.time_last_meal);
	create_thread(data, &data->philo->id_timer, &timer);
	// pthread_create(&data->philo->id_monitor, NULL, &timer, data);
}

void	detach_timer(t_list *data)
{
	detach_thread(data, &data->philo->id_timer);
	// pthread_detach(data->philo->id_monitor);
}
