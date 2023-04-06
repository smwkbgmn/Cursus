/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:15:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 00:02:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>

#include "push_swap.h"

void	push(t_stack **head, int data);

void	pa(t_stack **a, t_stack **b)
{
	if (*b != NULL)
	{
		push(a, (*b)->data);
		del_node(b);
	}
	printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a != NULL)
	{
		push(b, (*a)->data);
		del_node(a);
	}
	printf("pb\n");
}

void	push(t_stack **head, int data)
{
	t_stack	*node_move;
	
	// ft_stkadd_front(head, ft_stknew(data));
	ft_stkadd_back(head, );
	*head = (*head)->prev;
}

void	del_node(t_stack **head)
{
	t_stack	*del;

	del = *head;
	*head = del->next;
	(*head)->prev = del->prev;
	free(del);
}
