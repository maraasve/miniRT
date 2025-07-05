/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:32:05 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/05 12:18:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATIONS_H
# define CALCULATIONS_H

# include <tuples.h>

float	get_magnitude(t_tuple vector);
t_tuple	normalize(t_tuple vector);
float	get_dot_product(t_tuple vector1, t_tuple vector2);
t_tuple	get_cross_product(t_tuple vector1, t_tuple vector2);
float	ft_fabs(float a);
bool	equal_float(float a, float b);
float	degrees_to_radians(float degrees);
float	get_magnitude(t_tuple vector);

#endif