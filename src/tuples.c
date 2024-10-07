/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:05:55 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/02 12:02:34 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	same_tuple(t_tuple one, t_tuple two)
{
	if (equal_float(one.x, two.x) \
		&& equal_float(one.y, two.z) \
		&& equal_float(one.z, two.z) \
		&& equal_float(one.w, two.w))
		return (true);
	return (false);
}

t_tuple	add_tuple(t_tuple one, t_tuple two)
{
	t_tuple new;
	new.x = one.x + two.x;
	new.y = one.y + two.y;
	new.z = one.z + two.z;
	new.w = one.w + two.w;
	return (new);
}

t_tuple	subtract_tuple(t_tuple one, t_tuple two)
{
	t_tuple new;
	new.x = one.x - two.x;
	new.y = one.y - two.y;
	new.z = one.z - two.z;
	new.w = one.w - two.w;
	return (new);
}
