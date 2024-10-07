/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:48:24 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/07 17:57:57 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	translate_tuple(t_tuple tuple, t_tuple translation)
{
	t_tuple	result;

	if (tuple.w = 0)
		return (tuple);
	result.x = tuple.x + translation.x;
	result.y = tuple.y + translation.y;
	result.z = tuple.z + translation.z;
	return (result);
}

float **translation_matrix()