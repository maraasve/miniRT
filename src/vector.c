/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:16:15 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/01 14:40:48 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	is_vector(float arr[4])
{
	if (arr[w_index] == 0.0)
		return (true);
	return (false);
}

float	get_magnitude(float vector[4])
{
	float	magnitude;

	magnitude = sqrtf(powf(vector[x_index], 2) + powf(vector[y_index], 2) \
				+ powf(vector[z_index], 2) + powf(vector[w_index], 2));
	return (magnitude);
}

float	*normalize(float vector[4])
{
	float	*normalized;
	float	magnitude;
	normalized = malloc(sizeof(float) * 4);
	if (!normalized)
		return (NULL);
	magnitude = get_magnitude(vector);
	normalized[x_index] = vector[x_index] / magnitude;
	normalized[y_index] = vector[y_index] / magnitude;
	normalized[z_index] = vector[z_index] / magnitude;
	normalized[w_index] = vector[w_index] / magnitude;
	return (normalized);	
}

float	get_dot_product(float vector1[4], float vector2[4])
{
	float	dot_product;

	dot_product = vector1[x_index] * vector2[x_index] \
				+ vector1[y_index] * vector2[y_index] \
				+ vector1[z_index] * vector2[z_index] \
				+ vector1[w_index] * vector2[w_index];
	return (dot_product);
}

float	*get_cross_product(float vector1[4], float vector2[4])
{
	float	*cross_product;

	cross_product = malloc(sizeof(float) * 4);
	if (!cross_product)
		return (NULL);
	cross_product[x_index] = vector1[y_index] * vector2[z_index] \
							- vector1[z_index] * vector2[y_index];
	cross_product[y_index] = vector1[z_index] * vector2[x_index] \
							- vector1[x_index] * vector2[z_index];
	cross_product[z_index] = vector1[x_index] * vector2[y_index] \
							- vector1[y_index] * vector2[x_index];
	cross_product[w_index] = 0.0;
	return (cross_product);
}
