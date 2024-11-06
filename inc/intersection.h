/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/31 17:51:04 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <tuples.h>
# include <calculations.h>
# include <shapes.h>
# include <minirt.h>

typedef struct	s_intersection
{
	float					t;
	t_object				*object;
	struct s_intersection	*next;
}	t_intersection;

typedef struct s_comps
{
	float	t;
	t_object	*object;
	t_tuple	point;
	t_tuple	over_point;
	t_tuple	eyev;
	t_tuple	normalv;
	t_tuple	reflectv;
	bool	inside;
}	t_comps;

typedef struct	s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

t_comps			prepare_comps(t_intersection *intersection, t_ray ray);
t_intersection	*intersect_world(t_world *world, t_ray ray);
t_color			color_at(t_world *world, t_ray ray, int *remaining);
t_intersection	*get_hit(t_intersection *intersections);
t_tuple			position(t_ray ray, float time);
t_tuple			normal_at(t_object *shape, t_tuple point);

#endif