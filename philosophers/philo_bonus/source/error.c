/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:09:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 00:50:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "philo.h"

void	*errext(void *ptr)
{
	if (!ptr)
		exit_with_error(NULL, "malloc");
	return (ptr);
}

void	exit_with_error(t_list *data, char *msg)
{
	if (msg)
		perror(msg);
		// printf("%s\n", msg);
	if (data)
		del_semaphore(data);
	exit(EXIT_FAILURE);
}
