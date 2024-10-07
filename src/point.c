/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:17:37 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/02 11:39:46 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	is_point(t_tuple tuple)
{
	if (tuple.w == 1.0)
		return (true);
	return (false);
}

void	create_point(t_tuple *tuple, float x, float y, float z)
{
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = 1.0;
}
