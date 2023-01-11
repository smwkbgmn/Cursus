/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/11 20:59:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		get_width(char *format, t_list *head);
static size_t	get_len_full_str(t_list *head, short type);

short	flag_width(char *format, t_list *head)
{
	char	*spaces;
	int		width;

	width = get_width(format, head);
	if (width == ERROR)
	{
		printf("check here\n");
		return (FALSE);
	}
	else
	{
		if (width > 0)
		{
			spaces = get_str_fill_char(width, ' ');
			if (spaces)
				ft_lstidx(head, 0)->content = spaces;
			else
				return (FALSE);
		}
		return (TRUE);
	}
}

static int	get_width(char *format, t_list *head)
{
	unsigned long	width;

	format += pass_flag(format, 6);
	width = ft_atoi_ulong(format);
	if (width > 2147483636)
		width = ERROR;
	else
		width -= get_len_full_str(head, get_type_str(format));
	return (width);
}

static size_t	get_len_full_str(t_list *head, short type)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (head->content)
		{
			if (type_c_with_null(type, head->content))
				len += 1;
			else
				len += ft_strlen(head->content);
		}
		head = head->next;
	}
	return (len);
}
