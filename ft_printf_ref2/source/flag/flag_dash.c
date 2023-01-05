/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_dash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:41:58 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static size_t	get_len_full_str(t_list *head, short i_spcf);

void	flag_dash(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*spaces;
	int		width;

	str += pass_flag(str);
	width = ft_atoi(str) - get_len_full_str(*head, find_spcf(str));
	if (width > 0)
	{
		spaces = get_str_fill_char(width, ' ');
		if (spaces)
		{
			node_new = ft_lstnew(spaces);
			if (node_new)
				ft_lstadd_back(head, node_new);
		}
	}
}

static size_t	get_len_full_str(t_list *head, short i_spcf)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (i_spcf == 0 && ft_memcmp(head->content, "\0", 1) == 0)
			len += 1;
		else
			len += ft_strlen(head->content);
		head = head->next;
	}
	return (len);
}