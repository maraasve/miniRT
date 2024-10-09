/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:57:47 by marieke           #+#    #+#             */
/*   Updated: 2024/10/09 18:18:35 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	new;

	new.origin = origin;
	new.direction = direction;
	return (new);
}

t_tuple	position(t_ray ray, float time)
{
	t_tuple	new_pos;

	new_pos.x = ray.origin.x + ray.direction.x * time;
	new_pos.y = ray.origin.y + ray.direction.y * time;
	new_pos.z = ray.origin.z + ray.direction.z * time;
	new_pos.w = 1;
	return (new_pos);
}

float	get_discriminant(t_ray ray, t_tuple sphere_to_ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(b, 2) - 4 * a * c;
	return (discriminant);
}

t_intersection	intersect(t_ray ray, t_sphere sphere)
{
	t_intersection	xs;
	t_tuple			sphere_to_ray;
	float			discriminant;
	float			a; //dont like im calculating this twice, but will do for now
	float			b;

	sphere_to_ray = subtract_tuple(ray.origin, sphere.center);
	discriminant = get_discriminant(ray, sphere_to_ray);
	if (discriminant < 0)
	{
		xs.count = 0;
		return (xs);
	}
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	xs.count = 2;
	xs.t[0] = (-b - sqrtf(discriminant)) / (2 * a);
	xs.t[1] = (-b + sqrtf(discriminant)) / (2 * a);
	return (xs);
}
