/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:53:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 12:51:30 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_list *data, t_msec *last_meal, t_msec die);

void	*monitor(void *arg)
{
	t_list	*data;

	data = arg;
	set_time(data, &data->philo->info.time_last_meal);
	check_death(data,
		&data->philo->info.time_last_meal,
		data->share->config.time_die);
	return (NULL);
}

void	check_death(t_list *data, t_msec *last_meal, t_msec die)
{
	while (!ref_death(data))
	{
		printf("\t\tPhilo %d ref death : %d\n",
			data->philo->info.name, ref_death(data));
		if (get_time_elapsed(data, last_meal) > die)
		{
			set_death(data);
			print_death(data);
		}
		else
			suspend(10);
	}
}