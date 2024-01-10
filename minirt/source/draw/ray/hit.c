/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/09 11:34:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	is_interior(t_scl a, t_scl b, t_hit *rec);
static void		set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r);
static void		set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal);

t_bool	hit(t_list *objs, const t_ray *r, t_intvl t, t_hit *rec)
{
	t_hit		rec_tmp;
	t_bool		hit_anything = FALSE;
	t_scl		closest_so_far = t.max;
	// t_hit_fp	hit_object = ((t_obj *)objs->content)->hit;

	while (objs)
	{
		// if (hit_object(objs->content, r, interval_set(t.min, closest_so_far), &rec_tmp))
		if (((t_obj *)objs->content)->hit(objs->content,
			r, interval_set(t.min, closest_so_far), &rec_tmp))
		{
			hit_anything = TRUE;
			closest_so_far = rec_tmp.t;
			*rec = rec_tmp;
		}
		objs = objs->next;
	}
	return (hit_anything);
}

t_bool	hit_plane(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_scl	denom = dot(obj->val.sqr.normal, r->direc);

	// No hit if the ray is parallel to the plane
	if (fabs(denom) < 1e-8)
		return FALSE;

	// Return FALSE if the hit point parameter t is outside the ray interval
	t_scl	t = (obj->val.sqr.d - dot(obj->val.sqr.normal, r->origin)) / denom;
	if (!contains(t, ray_t))
		return FALSE;

	// Determine the hit point lies within the planar shape using its plane coord
	t_point	intersection = ray_at(r, t);
	t_vec	planar_hitpt_vector = sb(intersection, obj->val.sqr.point);
	t_scl	alpha = dot(obj->val.sqr.w, cross(planar_hitpt_vector, obj->val.sqr.v));
	t_scl	beta = dot(obj->val.sqr.w, cross(obj->val.sqr.u, planar_hitpt_vector));

	if (!is_interior(alpha, beta, rec))
		return FALSE;
	
	// Ray hits the 2D shape; set the rest of the hit record and return TRUE
	rec->t = t;
	rec->point = intersection;
	rec->mtral = obj->mtral;
	set_face_normal(rec, r, obj->val.sqr.normal);
	return (TRUE);
}

static t_bool	is_interior(t_scl a, t_scl b, t_hit *rec)
{
	/* GIven the hit point in plane coord, return FALSE if it is outside the
	primitive, otherwise set the hit record UV coord and return TRUE */
	
	if (a < 0 || 1 < a || b < 0 || 1 < b)
		return FALSE;

	rec->tx_u = a;
	rec->tx_v = b;
	return TRUE;
}

t_bool	hit_sphere(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
{
	t_eqa	eqa;

	t_scl	sqrtd;
	t_scl	root;
	t_vec	outward_normal;
	
	set_equation(&eqa, obj, r);
	if (eqa.dscr < 0)
		return (FALSE);
	
	sqrtd = sqrt(eqa.dscr);
	// Find the nearest root that lines in the acceptable range
	root = (-eqa.b_half - sqrtd) / eqa.a;
	if (!surrounds(root, t))
	{
		root = (-eqa.b_half + sqrtd) / eqa.a;
		if (!surrounds(root, t))
			return (FALSE);
	}

	rec->t = root;
	rec->point = ray_at(r, rec->t);

	outward_normal = dv(sb(rec->point, obj->val.cir.center), obj->val.cir.radius);
	set_face_normal(rec, r, outward_normal);
	rec->mtral = obj->mtral;

	return (TRUE);
}

static void	set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r)
{
	eqa->oc = sb(r->origin, obj->val.cir.center);
	eqa->a = square(r->direc);
	eqa->b_half = dot(eqa->oc, r->direc);
	eqa->c = square(eqa->oc) - pow(obj->val.cir.radius, 2);
	
	eqa->dscr = pow(eqa->b_half, 2) - (eqa->a * eqa->c);
}

static void	set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal)
{
	// The parameter 'outward_normal' is assumed to have unit len
	rec->face = dot(r->direc, outward_normal) < 0;
	if (rec->face)
		rec->normal = outward_normal;
	else
		rec->normal = mt(outward_normal, -1);
}
