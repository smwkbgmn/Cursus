/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:00:17 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/18 19:35:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdio.h>

# include "ray.h"

/* draw.c */
void	render(const t_scene *scene, const t_world *world);

/* scene.c */
t_camera	camera(t_point from, t_point at, t_uvec up, t_scl fov);
t_image		image(t_scl aspect, t_scl width);
t_view		viewport(const t_scene *scene);
t_point		point(t_scl x, t_scl y, t_scl z);

/* object.c */
t_light	*light(t_point position, t_color rgb, t_scl bright);
t_obj	*sphere(t_point center, t_scl radius, t_mtral mtral);
t_obj	*plane(t_point q, t_vec u, t_vec v, t_mtral mtral);
t_color	albedo_rgb(t_color rgb, t_scl ratio);

#endif