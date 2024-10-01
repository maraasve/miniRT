/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:05:55 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/01 13:18:53 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

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
