/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/11 17:26:07 by maraasve         ###   ########.fr       */
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
	t_ray	ray;
	ray.direction = create_vector(0, 1, 0);
	ray.origin = create_point(1, 2, 3);

	t_tuple	translate_tuple;
	translate_tuple.x = 2;
	translate_tuple.y = 3;
	translate_tuple.z = 4;
	t_matrix	transform = scale_matrix(translate_tuple);
	t_ray transformed = transform_ray(ray, transform);
	printf("%f\n", transformed.direction.x);
	return 0;
}
