/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:54:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 18:40:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status(t_thread *thread, t_stat stat_to_change)
{
	mtx_lock(&thread->philo.key_stat);
	if (thread->philo.stat != DEAD)
		thread->philo.stat = stat_to_change;
	mtx_unlock(&thread->philo.key_stat);
}

t_stat	ref_status(t_thread *thread)
{
	t_stat	result;

	mtx_lock(&thread->philo.key_stat);
	result = thread->philo.stat;
	mtx_unlock(&thread->philo.key_stat);
	return (result);
}

void	set_fork(t_thread *thread, t_bool bool_to_change)
{
	mtx_lock(&thread->philo.key_fork);
	thread->philo.fork = bool_to_change;
	mtx_unlock(&thread->philo.key_fork);
}

t_bool	ref_fork(t_thread *thread)
{
	t_bool	result;

	mtx_lock(&thread->philo.key_fork);
	result = thread->philo.fork;
	mtx_unlock(&thread->philo.key_fork);
	return (result);
}
