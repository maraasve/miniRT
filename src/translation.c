/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:48:24 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/11 17:25:35 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	translate_tuple(t_tuple tuple, t_tuple translation)
{
	t_tuple	result;

	if (tuple.w == 0)
		return (tuple);
	result.x = tuple.x + translation.x;
	result.y = tuple.y + translation.y;
	result.z = tuple.z + translation.z;
	return (result);
}

t_matrix	translation_matrix(t_tuple translation)
{
	t_matrix	new;

	new = create_identity_matrix();
	new.grid[0][3] = translation.x;
	new.grid[1][3] = translation.y;
	new.grid[2][3] = translation.z;
	return (new);
}

t_matrix	scale_matrix(t_tuple scale)
{
	t_matrix	new;

	new = create_identity_matrix();
	new.grid[0][0] = scale.x;
	new.grid[1][1] = scale.y;
	new.grid[2][2] = scale.z;
	return (new);
}

