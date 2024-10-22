/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/22 17:33:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	render(t_data *data, t_world *world)
{
	t_ray			ray;
	t_tuple			target;
	t_color			color;
	float			wall_z = 10;
	float			wall_size = 7.0;
	float			pixel_size = wall_size / HEIGHT;
	float			half = wall_size / 2;
	float			world_y;
	float			world_x;
	int				x;
	int				y;

	ray.origin = create_point(0, 0, -5);
	y = 0;
	while (y < HEIGHT)
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < WIDTH)
		{
			world_x = -half + pixel_size * x;
			target = create_point(world_x, world_y, wall_z);
			ray.direction = normalize(subtract_tuple(target, ray.origin));
			color = color_at(world, ray);
			pixel_put(data, x, y, color);
			//printf("PUT_PIXEL\n");
			free_intersection(&world->intersections);
			x++;
		}
		y++;
	}
}


int main(void)
{
	t_data			data;
	t_world			world;
	t_sphere		*sphere1;
	t_sphere		*sphere2;
	t_ray			ray;

	sphere1 = new_sphere(create_point(0, 0, 0), 1, default_material(), new_object_base(SPHERE, scale_matrix(0.5,0.5,0.5)));
	if (!sphere1)
		return (1);
	sphere2 = new_sphere(create_point(0, 0, 0), 1, default_material(), new_object_base(SPHERE, translation_matrix(1.5, 0, 2)));
	if (!sphere2)
		return (2);

	sphere1->material.color = new_color(1.0, 0.5, 0.8);

	sphere2->material.color = new_color(0.2, 0.8, 0.3);
	sphere2->material.ambient = 0.3;
	
	world.base = NULL;
	world.spheres = NULL;
	add_sphere_to_list(&world.spheres, sphere1);
	add_sphere_to_list(&world.spheres, sphere2);
	
	world.light = new_light(create_point(-600, 5, -100), new_color(1, 1, 1));

	world.intersections = NULL;

	ray.direction = create_vector(0,0,1);
	ray.origin = create_point(0, 0, -5);

	if (!init_mlx(&data))
		return (1);
	hooks(&data);
	render(&data, &world);
	mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
	printf("DONE\n");
	mlx_loop(data.mlx);
	free_mlx(&data);

	free(sphere1->base);
	free(sphere1);

	free(sphere2->base);
	free(sphere2);
}