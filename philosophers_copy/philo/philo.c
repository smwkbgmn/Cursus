/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:12:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 12:47:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Arguments 
1. number of philo (and fork)
2. time to die
3. time to eat
4. time to sleep
[5. number_of_times_each_philosopher_must_eat]
If all philosophers have eaten at least that times, the simulation stops.
If not specified, the simulation stops when a philosopher dies. */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_data	data;
	static t_list	*list;

	if ((ac == 5 || ac == 6)
		&& validate_input(av + 1))
	{
		init_data(ac, av, &data);
		init_philosophers(&list, &data);
		start_life(list, &data);
	}
	return (0);
}
