/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:07:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/01 18:01:33 by maraasve         ###   ########.fr       */
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

# define EPSILON 0.0001

enum e_xyzw
{
	x_index,
	y_index,
	z_index,
	w_index
};

typedef	struct s_color
{
	float	red;
	float	green;
	float	blue;
} t_color;

//tuples.c
bool	same_tuple(float one[4], float two[4]);
float	*add_tuple(float tuple1[4], float tuple2[4]);
float	*subtract_tuple(float tuple1[4], float tuple2[4]);

//point.c
bool	is_point(float arr[4]);
void	get_point(float tuple[4], float x, float y, float z);
void	get_point(float tuple[4], float x, float y, float z);

//vector.c
bool	is_vector(float arr[4]);
float	get_magnitude(float vector[4]);
float	*normalize(float vector[4]);
float	get_dot_product(float vector1[4], float vector2[4]);
float	*get_cross_product(float vector1[4], float vector2[4]);

//utils.c
float	ft_abs(float a);
bool	equal_float(float a, float b);

//colors.c
t_color	*add_colors(t_color one, t_color two);
t_color	*subtract_colors(t_color one, t_color two);
t_color	*colors_multi_scalar(t_color one, float scalar);
t_color	*colors_multiply(t_color one, t_color two);
#endif