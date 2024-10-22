/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:07:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/22 17:46:12 by maraasve         ###   ########.fr       */
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
# define HEIGHT 600
# define WIDTH 800
# define SUCCESS 0
# define ERROR 1

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
	float	r;
	float	g;
	float	b;
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
	int						type;
	t_matrix				transformation;
	struct s_object_base	*next;
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
	t_object_base	*base;
	struct s_sphere	*next;
}	t_sphere;

typedef struct	s_intersection
{
	float					t;
	void					*object;
	struct s_intersection	*next;
}	t_intersection;

typedef	struct s_point_light
{
	t_color	intensity;
	t_tuple	pos;
}	t_point_light;

typedef struct s_world
{
	t_object_base	*base;
	t_point_light	light;
	t_intersection	*intersections;
	t_sphere		*spheres;
}	t_world;

typedef struct s_comps
{
	float	t;
	void	*object;
	t_tuple	point;
	t_tuple	eyev;
	t_tuple	normalv;
	bool	inside;
}	t_comps;


//colors.c
t_color	new_color(float r, float g, float b);
t_color	add_colors(t_color one, t_color two);
t_color	subtract_colors(t_color one, t_color two);
t_color	colors_multi_scalar(t_color one, float scalar);
t_color	colors_multiply(t_color one, t_color two);
int		create_trgb(float t, float r, float g, float b);
t_color clamp_color(t_color color);

//computations.c
t_comps	prepare_comps(t_intersection *intersection, t_ray ray);

//free.c
void	free_mlx(t_data *data);
void	free_matrix(float **grid, int size);
void	free_intersection(t_intersection **intersection);
void	free_spheres(t_sphere **head);

//hooks.c
void	hooks(t_data *data);

//image.c
void	pixel_put(t_data *data, int x, int y, t_color color);

//init.c
int		init_mlx(t_data *data);

//intersection.c
int	intersect_sphere(t_world *world, t_ray ray, t_sphere *sphere);
int	intersect_world(t_world *world, t_ray ray);
t_intersection	*get_hit(t_intersection *intersections);
t_color	color_at(t_world *world, t_ray ray);

//invert_matrix.c
float		**submatrix(float **grid, int row, int col, int size);
float		**allocate_mem_matrix(int size);
float		determinant(float **grid, int size);
t_matrix	*invert_matrix(float **matrix, int size);

//light.c
t_tuple		light_vector(t_tuple intersection, t_tuple light_src);
t_tuple		normal_at(t_sphere *sphere, t_tuple point);
t_tuple		negate_vector(t_tuple vector);
t_tuple		reflect(t_tuple in, t_tuple normal);
t_point_light	new_light(t_tuple pos, t_color intensity);
t_material	default_material(void);
t_color		lighting(t_material m, t_point_light light, t_tuple pos, t_tuple eyev, t_tuple normalv);

//list.c
t_object_base	*new_object_base(int type, t_matrix transformation);
void	add_object_to_list(t_object_base **head, t_object_base *new);
void	add_sphere_to_list(t_sphere **head, t_sphere *new);

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
t_ray	transform_ray(t_ray ray, t_matrix transformation);

//rotation.c
t_tuple		rotate_x(t_tuple point, float radians);

//sphere.c
t_sphere	*new_sphere(t_tuple center, float radius, t_material material, t_object_base *base);

//transformation.c
t_tuple		translate_tuple(t_tuple tuple, float x, float y, float z);
t_matrix	translation_matrix(float x, float y, float z);
t_matrix	scale_matrix(float x, float y, float z);

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