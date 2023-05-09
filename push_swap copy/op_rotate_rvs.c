/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_rvs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:16:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 22:09:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_rotate_rvs(t_stack **head);

void	rra(t_stack **a)
{
	set_rotate_rvs(a);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	set_rotate_rvs(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	set_rotate_rvs(a);
	set_rotate_rvs(b);
	printf("rrr\n");
}

static void	set_rotate_rvs(t_stack **head)
{
	*head = (*head)->prev;
}
