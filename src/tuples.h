/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:07:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/07 17:41:54 by maraasve         ###   ########.fr       */
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

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef	struct s_color
{
	float	red;
	float	green;
	float	blue;
}	t_color;

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_env;

typedef struct s_matrix
{
	float	grid[4][4];
}	t_matrix;

//colors.c
t_color	*add_colors(t_color one, t_color two);
t_color	*subtract_colors(t_color one, t_color two);
t_color	*colors_multi_scalar(t_color one, float scalar);
t_color	*colors_multiply(t_color one, t_color two);

//free.c
void	free_mlx(t_data *data);
void	free_matrix(float **grid, int size);

//image.c
void	pixel_put(t_data *data, int x, int y, int color);

//init.c
void	init_p_and_env(t_projectile *p, t_env *env);
int		init_mlx(t_data *data);

//invert_matrix.c
float	**submatrix(float **grid, int row, int col, int size);
float	**allocate_mem_matrix(int size);
float	determinant(float **grid, int size);
float	**invert_matrix(float **matrix, int size);

//point.c
bool	is_point(t_tuple tuple);
void	create_point(t_tuple *tuple, float x, float y, float z);

//translation.c

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
void	create_vector(t_tuple *tuple, float x, float y, float z);
t_tuple	scale_vector(t_tuple vector, float scale);
float	get_magnitude(t_tuple vector);
t_tuple	normalize(t_tuple vector);
float	get_dot_product(t_tuple vector1, t_tuple vector2);
t_tuple	*get_cross_product(t_tuple vector1, t_tuple vector2);

#endif