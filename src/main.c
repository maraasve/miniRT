/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/14 18:01:52 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	render(t_data *data, t_sphere sphere)
{
	t_ray			ray;
	t_tuple			target;
	t_intersection	*intersection;
	t_intersection	*hit;
	float			wall_z = 10;
	float			wall_size = 7.0;
	float			pixel_size = wall_size / HEIGHT;
	float			half = wall_size / 2;
	float			world_y;
	float			world_x;
	int				x;
	int				y;
	int				count;


	ray.origin = create_point(0, 0, -5);
	y = 0;
	while (y < WIDTH)
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < HEIGHT)
		{
			world_x = -half + pixel_size * x;
			target = create_point(world_x, world_y, wall_z);
			ray.direction = normalize(subtract_tuple(target, ray.origin));
			count = 0;
			intersection = intersect(ray, sphere, &count);
			if (intersection)
			{
				hit = get_hit(intersection, count);
				if (hit)create_identity_matrix();
				{
					pixel_put(data, x, y, RED);
					printf("PUT THE PIXEL\n");
				}
				else
					pixel_put(data, x, y, BLACK);
				free(intersection);
			}
			else
				pixel_put(data, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int main(void)
{
	t_data		data;
	t_sphere	sphere;
	t_object_base base;
	t_tuple scale = create_point(0.5, 1, 0.5);
	
	base.transformation = scale_matrix(scale);

	sphere.center = create_point(0, 0, 0);
	sphere.radius = 1;
	sphere.base = base;
	if (!init_mlx(&data))
		return (1);
	hooks(&data);
	render(&data, sphere);
	mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
	mlx_loop(data.mlx);
	free_mlx(&data);
}
