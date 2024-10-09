/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/08 15:39:14 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

int	on_destroy(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int main(void)
{
	t_tuple point;

	create_point(&point, 0, 1, 0);
	point = rotate_x(point, M_PI / 2);
	printf("x = %f | y = %f | z = %f\n", point.x, point.y, point.z);
}
