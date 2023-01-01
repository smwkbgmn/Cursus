/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_x_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:24 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 09:47:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

t_list	*spcf_x_lower(va_list *ptr)
{
	t_list	*head;
	char	*dec;
	char	*hex;

	head = 0;
	dec = ft_itoa_long(va_arg(*ptr, unsigned int));
	if (dec)
	{
		hex = ft_convert_base_ul(dec, "0123456789", "0123456789abcdef");
		head = ft_lstnew(hex);
		free(hex);
		free(dec);
	}
	return (head);
}
