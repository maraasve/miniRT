/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:57:47 by marieke           #+#    #+#             */
/*   Updated: 2025/07/05 12:18:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

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
	t_ray	new;

	new.origin = multiply_matrix_tuple(transformation, ray.origin);
	new.direction = multiply_matrix_tuple(transformation, ray.direction);
	return (new);
}
