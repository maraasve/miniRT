/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:47:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/01 15:40:37 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_color	*add_colors(t_color one, t_color two)
{
	t_color *new;

	new = malloc(sizeof(t_color));
	if (!new)
		return (NULL);
	new->red = one.red + two.red;
	new->green = one.green + two.green;
	new->blue = one.blue + two.blue;
	return (new);
}

t_color	*subtract_colors(t_color one, t_color two)
{
	t_color *new;

	new = malloc(sizeof(t_color));
	if (!new)
		return (NULL);
	new->red = one.red - two.red;
	new->green = one.green - two.green;
	new->blue = one.blue - two.blue;
	return (new);
}

t_color	*colors_multi_scalar(t_color one, float scalar)
{
	t_color *new;

	new = malloc(sizeof(t_color));
	if (!new)
		return (NULL);
	new->red = one.red * scalar;
	new->green = one.green * scalar;
	new->blue = one.blue * scalar;
	return (new);
}

t_color	*colors_multiply(t_color one, t_color two)
{
	t_color *new;

	new = malloc(sizeof(t_color));
	if (!new)
		return (NULL);
	new->red = one.red * two.red;
	new->green = one.green * two.green;
	new->blue = one.blue * two.blue;
	return (new);
}

int	create_trgb(float t, float r, float g, float b)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	// Clamp the float values between 0 and 1, then scale to 0-255
	red = (int)(r * 255.0);
	green = (int)(g * 255.0);
	blue = (int)(b * 255.0);
	alpha = (int)(t * 255.0); // Transparency (optional, can set to 255 for full opacity)

	// Combine into a single int in the format 0xTTRRGGBB
	return (alpha << 24 | red << 16 | green << 8 | blue);
}