/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:13:56 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 17:12:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static int		count_ac(char **av);
static t_bool	valid(char *av);

void	bltin_exit(char **av)
{
	int	stat_exit;

	if (count_ac(av) > 2)
		set_error(NULL, "exit: too many arguments", 1);
	else
	{
		if (*(av + 1))
		{
			if (valid(*(av + 1)))
			{
				stat_exit = ft_atoi(*(av + 1));
				g_exit = stat_exit;
				ft_putstr("exit\n");
				exit(g_exit);
			}
			else
				set_error(*(av + 1), "numeric argument required", 255);
		}
		else
		{
			ft_putstr("exit\n");
			exit(g_exit);
		}
	}
}

static int	count_ac(char **av)
{
	int	ac;

	ac = 0;
	while (*av)
	{
		ac++;
		av++;
	}
	return (ac);
}

static t_bool	valid(char *av)
{
	while (ft_isdigit(*av))
		av++;
	return (*av == '\0');
}
