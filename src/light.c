/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:19:39 by marieke           #+#    #+#             */
/*   Updated: 2024/10/18 17:07:13 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	negate_vector(t_tuple vector)
{
	t_tuple	negated;

	negated.x = -vector.x;
	negated.y = -vector.y;
	negated.z = -vector.z;
	negated.w = vector.w;
	return (negated);
}

t_tuple	light_vector(t_tuple intersection, t_tuple light_src)
{
	t_tuple	light_vec;

	light_vec = subtract_tuple(light_src, intersection);
	return(light_vec);
}

t_tuple	normal_at(t_sphere sphere, t_tuple point)
{
	t_tuple		obj_normal;
	t_tuple		world_normal;
	t_matrix	*inverted;
	t_tuple		object_point;

	world_normal = create_vector(0, 0, 0); //need to fix error handling
	inverted = invert_matrix(sphere.base.transformation.grid, 4);
	if (!inverted)
		return (world_normal); //need to fix the error handling
	object_point = multiply_matrix_tuple(*inverted, point);
	obj_normal = subtract_tuple(object_point, sphere.center);
	world_normal = multiply_matrix_tuple(transpose_matrix(*inverted), obj_normal);
	free(inverted);
	world_normal.w = 0;
	world_normal = normalize(world_normal);
	return (world_normal);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	reflection;
	t_tuple	scaled_normal;
	float	dot;

	dot = get_dot_product(in, normal);
	scaled_normal = scale_vector(normal, 2 * dot);
	reflection = subtract_tuple(in, scaled_normal);
	return(reflection);
}

t_point_light	new_light(t_tuple pos, t_color color)
{
	t_point_light	new;

	new.pos = pos;
	new.intensity = color;
	return (new);
}

t_material	default_material(void)
{
	t_material	material;

	material.color.red = 1;
	material.color.green = 1;
	material.color.blue = 1;
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	return (material);
}

t_color	lighting(t_material m, t_point_light light, t_tuple pos, t_tuple eyev, t_tuple normalv)
{
	t_color	result;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	float	reflect_dot_eye;
	float	light_dot_normal;
	float	factor;

	effective_color = colors_multiply(m.color, light.intensity);
	lightv = normalize(subtract_tuple(light.pos, pos));
	ambient = colors_multi_scalar(effective_color, m.ambient);
	light_dot_normal = get_dot_product(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = new_color(0, 0, 0);
		specular = new_color(0, 0, 0);
	}
	else
	{
		diffuse = colors_multi_scalar(colors_multi_scalar(effective_color, m.diffuse), light_dot_normal);
		reflectv = reflect(negate_vector(lightv), normalv);
		reflect_dot_eye = get_dot_product(reflectv, eyev);
		if (reflect_dot_eye < 0)
			specular = new_color(0, 0, 0);
		else
		{
			factor = powf(reflect_dot_eye, m.shininess);
			specular = colors_multi_scalar(colors_multi_scalar(light.intensity, m.specular), factor);
		}
	}
	result = add_colors(add_colors(ambient, diffuse), specular);
	result = clamp_color(result);
	return (result);
}
