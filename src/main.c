/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:06:00 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/07 13:31:42 by maraasve         ###   ########.fr       */
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
	float grid[3][3];

	grid[0][0] = 3;
	grid[0][1] = 5;
	grid[0][2] = 0;
	grid[1][0] = 2;
	grid[1][1] = -1;
	grid[1][2] = -7;
	grid[2][0] = 6;
	grid[2][1] = -1;
	grid[2][2] = 5;

	printf("minor = %f\n", minor(grid, 1, 0, 3)); 
}