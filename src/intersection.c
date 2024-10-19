/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:39:19 by marieke           #+#    #+#             */
/*   Updated: 2024/10/19 15:06:40 by marieke          ###   ########.fr       */
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
}

void	sort_intersections(t_intersection **head)
{
	t_intersection	*one;
	t_intersection	*two;
	int				swapped;

	swapped = 1;
	one = *head;
	while (swapped)
	{
		swapped = 0;
		two = one->next;
		if (one->t > two->t)
		{
			
			swapped = 1;
		}
		one = one->next;
	}
}

void	add_intersection(t_intersection **head, t_intersection *new)
{
	t_intersection	*cur;

	if (!head || !new)
		return ;
	if (!*head)
	{
		head = new;
		return;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_intersection	*intersect_sphere(t_ray ray, t_sphere sphere, int *count)
{
	t_intersection	*xs;
	t_tuple			sphere_to_ray;
	t_matrix		*inverted;
	float			discriminant;
	float			a; //dont like im calculating this twice, but will do for now
	float			b;

	if (!is_identity_matrix(sphere.base->transformation.grid, 4))
	{
		inverted = invert_matrix(sphere.base->transformation.grid, 4);
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

void	intersect_world(t_world world, t_ray ray)
{

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