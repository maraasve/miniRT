/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/02 16:57:30 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void tick(t_env env, t_projectile *p)
{
	p->position = add_tuple(p->position, p->velocity);
	p->velocity = add_tuple(p->velocity, add_tuple(env.gravity, env.wind));
}

void	render_image(t_data *data, t_projectile p)
{
	int y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if ((int)round(p.position.x) == x && (HEIGHT - (int)round(p.position.y)) == y)
				pixel_put(data, x, y, (int)0xFF0000);
			else
				pixel_put(data, x, y, (int)0x000000);
			x++;
		}
		y++;
	}
}

int	on_destroy(t_data *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	program_loop(t_data *data)
{
	long long	now;
	long long	diffms;
	long long	last_ts;

	last_ts = millitimestamp();
	diffms = 0;
	while (data->p->position.y > 0)
	{
		now = millitimestamp();
		diffms = now - last_ts;
		if (diffms > 5000)
		{
			tick(*data->env, data->p);
			pixel_put(data, (int)round(data->p->position.x), HEIGHT - (int)round(data->p->position.y), (int)0xFF0000);
			mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
		}
	}
	return (0);
}

int main(void)
{
	t_projectile	p;
	t_env			env;
	t_data			data;
	
	init_p_and_env(&p, &env);
	data.p = &p;
	data.env = &env;
	if (!init_mlx(&data))
		return (1);

	mlx_hook(data.window, 17, 0, &on_destroy, &data);
	render_image(&data, p);
	mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
	mlx_loop_hook(data.mlx, &program_loop, &data);
	mlx_loop(data.mlx);
	free_mlx(&data);
}