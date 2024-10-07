/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:42:41 by marieke           #+#    #+#             */
/*   Updated: 2024/10/02 15:44:36 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	init_p_and_env(t_projectile *p, t_env *env)
{
	create_point(&p->position, 0, 1, 0);
	create_vector(&p->velocity, 6, 6, 0);
	p->velocity = normalize(p->velocity);
	p->velocity = scale_vector(p->velocity, 11.25);
	create_vector(&env->gravity, 0, -0.1, 0);
	create_vector(&env->wind, -0.01, 0, 0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "projectile");
	if (!data->window)
	{
		free(data->mlx);
		return (0);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		free_mlx(data);
		return (0);
	}
	data->addr = mlx_get_data_addr(data->image, &data->bpp,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
	{
		free_mlx(data);
		return (0);
	}
	return (1);
}