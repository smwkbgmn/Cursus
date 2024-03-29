/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:00:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/26 16:59:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static void	remove_file(char *name);
static void	free_cmd(t_data *input);
static void	free_path(char **path);

void	free_data(t_data *input)
{
	if (input->heredoc)
		remove_file("heredoc");
	if (input->fd_in != ERROR)
		close_fd(input->fd_in);
	close_fd(input->fd_out);
	free_cmd(input);
	if (input->path)
		free_path(input->path);
}

static void	remove_file(char *name)
{
	if (unlink(name) == ERROR)
		exit_with_error("unlink");
}

static void	free_cmd(t_data *input)
{
	int	idx;
	int	ptr;

	idx = 0;
	while (idx < input->cnt_cmd)
	{
		ptr = 0;
		while (input->cmd[idx].av[ptr])
		{
			ft_free(input->cmd[idx].av[ptr]);
			ptr++;
		}
		ft_free(input->cmd[idx].av);
		ft_free(input->cmd[idx].name);
		idx++;
	}
}

static void	free_path(char **path)
{
	int	ptr;

	ptr = 0;
	while (path[ptr])
	{
		ft_free(path[ptr]);
		ptr++;
	}
	ft_free(path);
}
