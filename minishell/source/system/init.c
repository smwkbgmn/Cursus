/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:26:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 12:36:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

void	init_shell(t_list **l_exe, char *line)
{
	get_command(l_exe, parse(line));
	// printf("init_process done\n");
	free(line);
	// dbg_print_procs(exe->l_procs);
}

// void	init_shell(t_execute *exe, char *line)
// {
// 	exe->l_token = parse(line);
// 	exe->l_procs = get_command(exe->l_token);
// 	// printf("init_process done\n");
// 	free(line);
// 	// dbg_print_procs(exe->l_procs);
// }
