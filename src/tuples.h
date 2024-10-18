/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:07:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/18 17:06:12 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <math.h>
# include "minirt.h"
# include "../lib/mlx_linux/mlx.h"
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define EPSILON 0.0001
# define MS 4
# define HEIGHT 100
# define WIDTH 100
# define RED 0xFF0000
# define BLACK 0x000000

typedef enum
{
	SPHERE,
	CUBE
} t_object_type;

typedef struct	s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef	struct	s_color
{
	float	red;
	float	green;
	float	blue;
}	t_color;

typedef struct	s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct	s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_env;

typedef struct	s_matrix
{
	float	**grid;
	int		size;
}	t_matrix;

typedef struct	s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef	struct	s_object_base
{
	int			object_type;
	t_matrix	transformation;
}	t_object_base;

typedef struct s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct	s_sphere
{
	t_tuple			center;
	float			radius;
	t_material		material;
	t_object_base	base;
}	t_sphere;

typedef struct	s_intersection
{
	int		count;
	float	t;
	void	*object;
}	t_intersection;

typedef	struct s_point_light
{
	t_color	intensity;
	t_tuple	pos;
}	t_point_light;

//colors.c
t_color	new_color(float r, float g, float b);
t_color	add_colors(t_color one, t_color two);
t_color	subtract_colors(t_color one, t_color two);
t_color	colors_multi_scalar(t_color one, float scalar);
t_color	colors_multiply(t_color one, t_color two);
int		create_trgb(float t, float r, float g, float b);
t_color clamp_color(t_color color);

//free.c
void	free_mlx(t_data *data);
void	free_matrix(float **grid, int size);

//hooks.c
void	hooks(t_data *data);

//image.c
void	pixel_put(t_data *data, int x, int y, t_color color);

//init.c
int		init_mlx(t_data *data);

//invert_matrix.c
float		**submatrix(float **grid, int row, int col, int size);
float		**allocate_mem_matrix(int size);
float		determinant(float **grid, int size);
t_matrix	*invert_matrix(float **matrix, int size);

//light.c
t_tuple		light_vector(t_tuple intersection, t_tuple light_src);
t_tuple		normal_at(t_sphere sphere, t_tuple point);
t_tuple		negate_vector(t_tuple vector);
t_tuple		reflect(t_tuple in, t_tuple normal);
t_point_light	new_light(t_tuple pos, t_color color);
t_material	default_material(void);
t_color		lighting(t_material m, t_point_light light, t_tuple pos, t_tuple eyev, t_tuple normalv);

//matrix.c
t_matrix	create_identity_matrix(void);
t_tuple		multiply_matrix_tuple(t_matrix matrix, t_tuple tuple);
t_matrix	transpose_matrix(t_matrix matrix);
bool		is_identity_matrix(float **matrix, int size);

//point.c
bool	is_point(t_tuple tuple);
t_tuple	create_point(float x, float y, float z);

//rays.c
t_tuple	position(t_ray ray, float time);
t_intersection	*intersect(t_ray ray, t_sphere sphere, int *count);
t_intersection	*get_hit(t_intersection *intersections, int count);
t_ray	transform_ray(t_ray ray, t_matrix transformation);

//rotation.c
t_tuple		rotate_x(t_tuple point, float radians);

//translation.c
t_tuple		translate_tuple(t_tuple tuple, t_tuple translation);
t_matrix	translation_matrix(t_tuple translation);
t_matrix	scale_matrix(t_tuple scale);

//tuples.c
bool	same_tuple(t_tuple one, t_tuple two);
t_tuple	add_tuple(t_tuple one, t_tuple two);
t_tuple	subtract_tuple(t_tuple one, t_tuple two);

//utils.c
float	ft_abs(float a);
bool	equal_float(float a, float b);
long long	millitimestamp(void);

//vector.c
bool	is_vector(t_tuple tuple);
t_tuple	create_vector(float x, float y, float z);
t_tuple	scale_vector(t_tuple vector, float scale);
float	get_magnitude(t_tuple vector);
t_tuple	normalize(t_tuple vector);
float	get_dot_product(t_tuple vector1, t_tuple vector2);
t_tuple	*get_cross_product(t_tuple vector1, t_tuple vector2);

#endif