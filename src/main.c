/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/18 17:18:21 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	render(t_data *data, t_sphere sphere, t_point_light light)
{
	t_ray			ray;
	t_tuple			target;
	t_tuple			point;
	t_tuple			normal;
	t_tuple			eye;
	t_intersection	*intersection;
	t_intersection	*hit;
	t_color			color;
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
				if (hit)
				{
					point = position(ray, hit->t);
					normal = normal_at(sphere, point);
					eye = negate_vector(ray.direction);
					color = lighting(sphere.material, light, point, eye, normal);
					pixel_put(data, x, y, color);
				}
				else
					pixel_put(data, x, y, new_color(0, 0, 0));
				free(intersection);
			}
			else
				pixel_put(data, x, y, new_color(0, 0, 0));
			x++;
		}
		y++;
	}
}

int main(void)
{
	t_data		data;
	t_sphere	sphere;
	t_material	material;
	t_object_base base;
	t_point_light light;

	base.transformation = create_identity_matrix();

	material = default_material();
	material.color = new_color(1, 0.2, 0.5);
	sphere.material = material;

	sphere.center = create_point(0, 0, 0);
	sphere.radius = 1;
	sphere.base = base;

	light = new_light(create_point(-5, 5, -5), new_color(1, 1, 1));

	if (!init_mlx(&data))
		return (1);
	hooks(&data);
	render(&data, sphere, light);
	mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
	mlx_loop(data.mlx);
	free_mlx(&data);
}
