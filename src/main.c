/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/07 17:35:08 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

int	on_destroy(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int main(void)
{
	float **grid;

	grid = allocate_mem_matrix(4);
	grid[0][0] = -5;
	grid[0][1] = 2;
	grid[0][2] = 6;
	grid[0][3] = -8;
	grid[1][0] = 1;
	grid[1][1] = -5;
	grid[1][2] = 1;
	grid[1][3] = 8;
	grid[2][0] = 7;
	grid[2][1] = 7;
	grid[2][2] = -6;
	grid[2][3] = -7;
	grid[3][0] = 1;
	grid[3][1] = -3;
	grid[3][2] = 7;
	grid[3][3] = 4;

	float **inverted = invert_matrix(grid, 4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%f ", inverted[i][j]);
		}
		printf("\n");
	}
}
