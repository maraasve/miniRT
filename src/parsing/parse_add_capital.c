/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_capital.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:31:28 by spenning          #+#    #+#             */
/*   Updated: 2025/07/05 16:14:39 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parse.h>
#include <list.h>
#include <calculations.h>
#include <camera.h>
#include <free.h>

void	parse_add_ambient(t_world *world, char *str)
{
	int	i;

	i = 1;
	world->ambientf = parse_get_float(str, &i);
	world->ambient = parse_get_color(str, &i);
	return ;
}

void	parse_add_camera(t_world *world, char *str)
{
	t_matrix	view;
	t_tuple		up;
	int			i;

	i = 1;
	world->cam.pos = parse_get_coordinates(str, &i);
	world->cam.normal = parse_get_normal(str, &i);
	if (!equal_float(ft_fabs(get_magnitude(world->cam.normal)), 1))
		world->cam.normal = normalize(world->cam.normal);
	up = create_vector(0, 1, 0);
	view = view_transform(&world->cam, world->cam.pos, world->cam.normal, up);
	new_camera(&world->cam, degrees_to_radians(parse_get_float(str, &i)), view);
	return ;
}

void	parse_add_light(t_world *world, char *str)
{
	t_tuple	pos;
	t_color	color;
	float	brightness;
	int		i;
	t_light	*light;

	i = 1;
	pos = parse_get_coordinates(str, &i);
	brightness = parse_get_float(str, &i);
	color = parse_get_color(str, &i);
	light = new_light(pos, color, brightness);
	if (!light)
		set_error(world, 1, LIGHT, NULL);
	if (!world->exit_code)
		add_light_to_list(&world->lights, light);
	return ;
}
