/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:20:00 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/05 12:18:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lighting.h>

t_light	*new_light(t_tuple pos, t_color color, float brightness)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->pos = pos;
	new->color = color;
	new->brightness = brightness;
	new->next = NULL;
	return (new);
}
