/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:47:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 15:03:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <unistd.h>

# include "parse.h"

# define R 0
# define W 1

typedef struct s_command	t_cmd;
typedef struct s_execute	t_exe;

// execute.c
void	get_execute(t_list **l_exe, t_list *l_token);

// utill.c
void	free_path(char **path);
t_meta	ref_type(t_list *l_token);
t_bool	is_redirect(t_list *l_token);
t_bool	is_prntsis(t_list *l_token);
t_bool	is_sequence(t_list *l_token);

// get_cmd.c
t_exe	*get_command(t_list *l_token);

// get_cmd_rd.c
void	assign_rd(t_exe *exe, t_meta type, char *value, t_bool *rd_fail);
void	apply_rd(t_exe *exe, t_exe *tmp);

// get_path.c
char	*get_path(char **path, char *av_cmd);

// get_heredoc.c
int		get_heredoc(char *tmpfile, char *delim);
void	write_heredoc(int fd_heredoc, char *limiter);

// get_heredoc_fork.c
void	fork_heredoc(char *fname, char *delim);

struct s_command
{
	char	*path;
	char	**av;
	int		fd_rd[2];
	char	*fname_heredoc;
};

struct s_execute
{
	t_cmd	cmd;
	t_meta	op_seq;
};

#endif