/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:39:19 by marieke           #+#    #+#             */
/*   Updated: 2024/10/22 17:19:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

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

t_intersection	*new_intersection(float t, void *object)
{
	t_intersection *new = malloc(sizeof(t_intersection));
	if (!new)
		return (NULL);
	new->t = t;
	new->object = object;
	new->next = NULL;
	return (new);
}

int	add_intersection_sorted(t_intersection **head, t_intersection *new)
{
	t_intersection	*cur;
	t_intersection	*prev;

	if (!head || !new)
		return (ERROR);
	if (!*head || (*head)->t >= new->t)
	{
		new->next = *head;
		*head = new;
		return (SUCCESS);
	}
	prev = NULL;
	cur = (*head);
	while (cur && cur->t < new->t)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
	return (SUCCESS);
}

int	intersect_sphere(t_world *world, t_ray ray, t_sphere *sphere)
{
	t_tuple			sphere_to_ray;
	t_matrix		*inverted;
	float			discriminant;
	float			t;
	float			a; //dont like im calculating this twice, but will do for now
	float			b;

	if (!is_identity_matrix(sphere->base->transformation.grid, 4))
	{
		inverted = invert_matrix(sphere->base->transformation.grid, 4);
		if (!inverted)
			return (ERROR);
		ray = transform_ray(ray, *inverted);
	}
	sphere_to_ray = subtract_tuple(ray.origin, sphere->center);
	discriminant = get_discriminant(ray, sphere_to_ray);
	if (discriminant < 0)
		return (SUCCESS);
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	t = (-b - sqrtf(discriminant)) / (2 * a);
	add_intersection_sorted(&world->intersections, new_intersection(t, (void *)sphere));
	t = (-b + sqrtf(discriminant)) / (2 * a);
	add_intersection_sorted(&world->intersections, new_intersection(t, (void *)sphere));
	return (SUCCESS);
}

int	intersect_world(t_world *world, t_ray ray)
{
	t_sphere *cur;

	cur = world->spheres;
	while (cur)
	{
			if (intersect_sphere(world, ray, cur) == ERROR)
				return (ERROR);
		cur = cur->next;
	}
	return (SUCCESS);
}

t_intersection	*get_hit(t_intersection *intersections)
{
	t_intersection	*cur;

	cur = intersections;
	while (cur)
	{
		if (cur->t > 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_color	shade_hit(t_world world, t_comps comps)
{
	t_sphere *sphere;

	sphere = (t_sphere *)comps.object;

	return (lighting(sphere->material, world.light, comps.point, comps.eyev, comps.normalv));
}

t_color	color_at(t_world *world, t_ray ray)
{
	t_comps	comps;
	t_intersection *hit;

	intersect_world(world, ray);
	hit = get_hit(world->intersections);
	if (!hit)
		return (clamp_color(new_color(0, 0, 0)));
	
	comps = prepare_comps(hit, ray);
	return (shade_hit(*world, comps));
}