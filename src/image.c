/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:25:06 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/18 16:54:03 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

// void	pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
// 	{
// 		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
// 		*(unsigned int *)dst = color;
// 	}
// }

void	pixel_put(t_data *data, int x, int y, t_color color)
{
	char	*dst;
	int		color_int;

	color_int = create_trgb(255, color.red, color.green, color.blue);
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color_int;
	}
}
