/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/04 15:21:12 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "tuples.h"
# include "color.h"
# include <stdbool.h>
# include <math.h>
# include <shapes.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define SUCCESS 0
# define ERROR 1
# define EPSILON 0.0001

typedef	struct s_light
{
	t_color			intensity;
	t_tuple			pos;
	struct s_light	*next;
}	t_light;

typedef struct s_world
{
	t_light			*lights;
	t_color			ambient;
	float			ambientf;
	//t_camera		*cam;
	t_object		*shapes;
}	t_world;

#endif
