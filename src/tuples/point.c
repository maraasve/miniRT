/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:17:37 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/05 12:18:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

bool	is_point(t_tuple tuple)
{
	if (tuple.w == 1.0)
		return (true);
	return (false);
}

t_tuple	create_point(float x, float y, float z)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 1.0;
	return (new);
}
