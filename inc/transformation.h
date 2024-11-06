/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:46:56 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/31 17:46:14 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

# include <tuples.h>
# include <matrix.h>
# include <intersection.h>

typedef struct s_transformation
{
	t_matrix	scale;
	t_matrix	translation;
	t_matrix	rotate;
}	t_transformation;

t_tuple		translate_tuple(t_tuple tuple, float x, float y, float z);
t_matrix	translation_matrix(float x, float y, float z);
t_matrix	scale_matrix(float x, float y, float z);
t_matrix	rotate(float x, float y, float z);
t_matrix	transformation_matrix(t_transformation transform);
t_ray		transform_ray(t_ray ray, t_matrix transformation);

#endif