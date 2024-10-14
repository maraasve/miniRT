/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:57:47 by marieke           #+#    #+#             */
/*   Updated: 2024/10/14 17:31:22 by maraasve         ###   ########.fr       */
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

t_ray	transform_ray(t_ray ray, t_matrix transformation)
{
	t_ray	transformed;

	transformed.origin = multiply_matrix_tuple(transformation, ray.origin);
	transformed.direction = multiply_matrix_tuple(transformation, ray.direction);
	return (transformed);
}

float	get_discriminant(t_ray ray, t_tuple sphere_to_ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	c = get_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(b, 2) - 4 * a * c;
	return (discriminant);
}

t_intersection	*intersect(t_ray ray, t_sphere sphere, int *count)
{
	t_intersection	*xs;
	t_tuple			sphere_to_ray;
	t_matrix		*inverted;
	float			discriminant;
	float			a; //dont like im calculating this twice, but will do for now
	float			b;

	if (!is_identity_matrix(sphere.base.transformation.grid, 4))
	{
		inverted = invert_matrix(sphere.base.transformation.grid, 4);
		if (!inverted)
			return (NULL);
		ray = transform_ray(ray, *inverted);
	}
	sphere_to_ray = subtract_tuple(ray.origin, sphere.center);
	discriminant = get_discriminant(ray, sphere_to_ray);
	if (discriminant < 0)
	{
		(*count) = 0;
		return (NULL);
	}
	(*count) = 2;
	xs = malloc(sizeof(t_intersection) * 2); // maybe intersections should be a linked list?
	if (!xs)
		return (NULL);
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	xs[0].t = (-b - sqrtf(discriminant)) / (2 * a);
	xs[0].object = (void *)&sphere;
	xs[1].t = (-b + sqrtf(discriminant)) / (2 * a);
	xs[1].object = (void *)&sphere;
	return (xs);
}

t_intersection	*get_hit(t_intersection *intersections, int count)
{
	int				i;
	t_intersection	*hit;

	hit = NULL;
	i = 0;
	while (i < count)
	{
		if (intersections[i].t > 0)
		{
			if (!hit || intersections[i].t < hit->t)
				hit = & intersections[i];
		}
		i++;
	}
	return (hit);
}

