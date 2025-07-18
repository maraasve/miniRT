/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:16:15 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/05 12:18:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>
#include <calculations.h>

bool	is_vector(t_tuple tuple)
{
	if (tuple.w == 0.0)
		return (true);
	return (false);
}

t_tuple	create_vector(float x, float y, float z)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 0.0;
	return (new);
}

t_tuple	scale_vector(t_tuple vector, float scale)
{
	t_tuple	new;

	new.x = vector.x * scale;
	new.y = vector.y * scale;
	new.z = vector.z * scale;
	new.w = vector.w * scale;
	return (new);
}

t_tuple	negate_vector(t_tuple vector)
{
	t_tuple	negated;

	negated.x = -vector.x;
	negated.y = -vector.y;
	negated.z = -vector.z;
	negated.w = vector.w;
	return (negated);
}

t_tuple	normalize(t_tuple vector)
{
	t_tuple	normalized;
	float	magnitude;

	magnitude = get_magnitude(vector);
	normalized.x = vector.x / magnitude;
	normalized.y = vector.y / magnitude;
	normalized.z = vector.z / magnitude;
	normalized.w = vector.w / magnitude;
	return (normalized);
}
