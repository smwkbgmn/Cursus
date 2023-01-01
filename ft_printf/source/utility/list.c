/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 22:13:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

static t_list	*get_list_value(va_list *ptr, short i_spcf);
static void		get_list_flag(const char *str, t_list **head);
static short	*get_switchs(const char *str);
static short	check_str(const char *str, short i_flag);

t_list	*get_list(const char *str, va_list *ptr, size_t l_flag)
{
	t_list	*head;

	head = get_list_value(ptr, get_spcf(str[l_flag]));
	if (head)
		get_list_flag(str, &head);
	return (head);
}

static t_list	*get_list_value(va_list *ptr, short i_spcf)
{
	t_list		*(*specifiers[8])(va_list *);

	set_spcf(specifiers);
	return (specifiers[i_spcf](ptr));
}

static void	get_list_flag(const char *str, t_list **head)
{
	void	(*flags[7])(const char *, t_list **head);
	short	*switchs;
	short	i_flag;

	set_flag(flags);
	switchs = get_switchs(str);
	if (switchs)
	{
		i_flag = 0;
		while (i_flag < 7)
		{
			if (switchs[i_flag] == 1)
				flags[i_flag](str, head);
			i_flag++;
		}
		free(switchs);
	}
}

static short	*get_switchs(const char *str)
{
	short	*switchs;
	short	i_flag;

	switchs = ft_calloc(7, 4);
	if (switchs)
	{
		i_flag = 0;
		while (i_flag < 7)
		{
			if ((i_flag == 1 || i_flag == 4) && switchs[i_flag - 1] == 1)
			{
				// printf("condition 1\n");
				i_flag++;
			}
			// "dash" with "zero" and "field witdth"
			else if ((i_flag == 4 || i_flag == 6) && switchs[5] == 1)
			{
				// printf("condition 2\n");
				i_flag++;
			}
			else if (i_flag == 6 && switchs[4] == 1)
			{
				// printf("condition 3\n");
				i_flag++;
			}
			else
			{
				switchs[i_flag] = check_str(str, i_flag);
				// printf("switchs[%d] --- [%d]\n", i_flag, switchs[i_flag]);
				i_flag++;
			}
		}
	}
	return (switchs);
}

static short	check_str(const char *str, short i_flag)
{
	size_t	idx;

	idx = 0;
	while (get_spcf(str[idx]) == -1)
	{
		if (i_flag == 6)
		{
			if (!(get_flag(str[idx]) < 3 || str[idx] == '0'))
				break ;
		}
		else
		{
			if (get_flag(str[idx]) == i_flag)
				break ;
		}
		idx++;
	}
	if (get_flag(str[idx]) == i_flag)
		return (1);
	else
		return (0);
}
