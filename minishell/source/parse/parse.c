/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 23:41:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

t_list	*parse(char *line)
{
	t_list	*l_token;
	char	*line_new;

	l_token = NULL;
	line_new = ft_strdup(line);
	lexer(line_new, &l_token);
	// lexer(line, &l_token);
	expand_wildcard(l_token);
	dbg_print_token(l_token);
	// free(line);
	// free(line_new);
	return (l_token);
}

t_list	*list_metachar(t_list *l_token, t_meta name)
{
	if (!l_token || ((t_token *)l_token->content)->type == name)
		return (l_token);
	else
		return (list_metachar(l_token->next, name));
}
