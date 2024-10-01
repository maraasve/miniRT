/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:17:37 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/01 13:32:32 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	is_point(float arr[4])
{
	if (arr[w_index] == 1.0)
		return (true);
	return (false);
}

void	get_point(float tuple[4], float x, float y, float z)
{
	tuple[x_index] = x;
	tuple[y_index] = y;
	tuple[z_index] = z;
	tuple[w_index] = 1.0;
}
