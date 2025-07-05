/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:59 by maraasve          #+#    #+#             */
/*   Updated: 2025/07/05 11:35:24 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_mlx.h>
#include <mlx.h>
#include <camera.h>
#include <free.h>
#include <matrix.h>
#include <transformation.h>

int	keypress(int keycode, t_mlx *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	return (1);
}

int	destroy(t_mlx *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	hooks(t_mlx *data)
{
	mlx_hook(data->window, 2, 1L << 0, keypress, data);
	mlx_hook(data->window, 17, 0L, destroy, data);
}
