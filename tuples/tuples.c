/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:05:55 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/30 17:59:55 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

bool	is_point(float arr[4])
{
	if (arr[w_index] == 1.0)
		return (true);
	return (false);
}

bool	is_vector(float arr[4])
{
	if (arr[w_index] == 0.0)
		return (true);
	return (false);
}

void	get_point(float tuple[4], float x, float y, float z)
{
	tuple[x_index] = x;
	tuple[y_index] = y;
	tuple[z_index] = z;
	tuple[w_index] = 1.0;
}

void	get_point(float tuple[4], float x, float y, float z)
{
	tuple[x_index] = x;
	tuple[y_index] = y;
	tuple[z_index] = z;
	tuple[w_index] = 0.0;
}

bool	equal_float(float a, float b)
{
	if (ft_abs(a - b) > EPSILON)
		return (false);
	return (true);
}

bool	same_tuple(float one[4], float two[4])
{
	if (equal_float(one[x_index], two[x_index]) \
		&& equal_float(one[y_index], two[z_index]) \
		&& equal_float(one[z_index], two[z_index]) \
		&& equal_float(one[w_index], two[w_index]))
		return (true);
	return (false);
}

float	*add_tuple(float tuple1[4], float tuple2[4])
{
	float *new;
	new = malloc(sizeof(float) * 4);
	if (!new)
		return (NULL);
	new[x_index] = tuple1[x_index] + tuple2[x_index];
	new[y_index] = tuple1[y_index] + tuple2[y_index];
	new[z_index] = tuple1[z_index] + tuple2[z_index];
	new[w_index] = tuple1[w_index] + tuple2[w_index];
	return (new);
}

float	*subtract_tuple(float tuple1[4], float tuple2[4])
{
	float *new;
	new = malloc(sizeof(float) * 4);
	if (!new)
		return (NULL);
	new[x_index] = tuple1[x_index] - tuple2[x_index];
	new[y_index] = tuple1[y_index] - tuple2[y_index];
	new[z_index] = tuple1[z_index] - tuple2[z_index];
	new[w_index] = tuple1[w_index] - tuple2[w_index];
	return (new);
}
