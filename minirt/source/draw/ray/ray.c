/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 14:51:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_hitbl	hittable(const t_ray *r, t_list *objs);
static t_color	color(t_scl x, t_scl y, t_scl z);

t_ray	ray(t_point origin, t_vec direc)
{
	t_ray	r;

	r.origin = origin;
	r.direc = direc;
	return (r);
}

t_point	ray_at(const t_ray *r, t_scl t)
{
	return (ad(r->origin, mt(r->direc, t)));
}

t_color	ray_color(const t_ray *r, t_list *objs)
{
	// SPHERE
	t_hit	rec;
	if (hit(hittable(r, objs), &rec))
		return (mt(ad(rec.normal, color(1, 1, 1)), 0.5));

	// SKY
	t_uvec	unit_direc = unit(r->direc);
	t_scl	scale = 0.5 * (unit_direc.y + 1.0);
	return (ad(mt(color(1.0, 1.0, 1.0), 1.0 - scale), mt(color(0.5, 0.7, 1.0), scale)));
}

static t_hitbl	hittable(const t_ray *r, t_list *objs)
{
	t_hitbl	able;

	able.r = r;
	able.t[MIN] = 0;
	able.t[MAX] = INFINITY;
	able.objs = objs;
	return (able);
}

static t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}