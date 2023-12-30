/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:22:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/29 16:37:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_scl	vdot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x
		+ v1.y * v2.y
		+ v1.z * v2.z);
}

t_vec	vcross(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.y * v2.z - v1.z * v2.y;
	rst.y = v1.z * v2.x - v1.x * v2.z;
	rst.z = v1.x * v2.y - v1.y * v2.x;
	return (rst);
}