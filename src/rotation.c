/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:45 by marieke           #+#    #+#             */
/*   Updated: 2024/10/09 16:33:06 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	rotate_x(t_tuple point, float radians)
{
	t_matrix	rotation;
	t_tuple		new_point;

	rotation = create_identity_matrix();
	rotation.grid[1][1] = cosf(radians);
	rotation.grid[1][2] = -sinf(radians);
	rotation.grid[2][1] = sinf(radians);
	rotation.grid[2][2] = cosf(radians);
	new_point = multiply_matrix_tuple(rotation, point);
	return (new_point);
}

t_tuple	rotate_y(t_tuple point, float radians)
{
	t_matrix	rotation;
	t_tuple		new_point;

	rotation = create_identity_matrix();
	rotation.grid[0][0] = cosf(radians);
	rotation.grid[0][2] = sinf(radians);
	rotation.grid[2][0] = -sinf(radians);
	rotation.grid[2][2] = cosf(radians);
	new_point = multiply_matrix_tuple(rotation, point);
	return (new_point);
}

t_tuple	rotate_z(t_tuple point, float radians)
{
	t_matrix	rotation;
	t_tuple		new_point;

	rotation = create_identity_matrix();
	rotation.grid[0][0] = cosf(radians);
	rotation.grid[0][1] = -sinf(radians);
	rotation.grid[1][0] = sinf(radians);
	rotation.grid[1][1] = cosf(radians);
	new_point = multiply_matrix_tuple(rotation, point);
	return (new_point);
}

// t_tuple	shearing(t_tuple point, ....)
// {
// 	t_tuple		new_point;
// 	t_matrix	shear_matrix;

// 	shear_matrix = create_identity_matrix();
	
// } not sure if we'll need this