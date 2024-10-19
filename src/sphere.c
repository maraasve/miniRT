/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:06:16 by marieke           #+#    #+#             */
/*   Updated: 2024/10/19 13:21:31 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_sphere	*new_sphere(t_tuple center, float radius, t_material material, t_object_base *base)
{
	t_sphere	*new;

	if (!base)
		return (NULL);
	new = malloc(sizeof(t_sphere));
	if (!new)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->material = material;
	new->base = base;
	return (new);
}