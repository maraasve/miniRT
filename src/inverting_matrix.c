/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverting_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:50:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/07 13:44:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	determinant(float **grid)
{
	float	determinant;

	determinant = grid[0][0] * grid[1][1] - grid[0][1] * grid[1][0];
	return (determinant);
}

float	**allocate_mem_matrix(int size)
{
	float	**new;
	int		i;

	new = malloc(sizeof(float *) * size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = malloc(sizeof(float) * size);
		if (!new)
		{
			free_matrix(new, i);
			return (NULL);
		}
		i++;
	}
	return (new);
}

float	**submatrix(float grid[3][3], int row, int col, int size)
{
	float	**sub;
	int		i;
	int		j;
	int		new_row;
	int		new_col;

	sub = allocate_mem_matrix(size - 1);
	if (!sub)
		return (NULL);
	i = 0;
	new_row = 0;
	new_col = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != row && j != col)
			{
				sub[new_row][new_col++] = grid[i][j];
				if (new_col == size - 1)
				{
					new_col = 0;
					new_row++;
				}
			}
			j++;
		}
		i++;
	}
	return (sub);
}

float	minor(float grid[3][3], int row, int col, int size)
{
	float	**sub;
	float	minor;

	sub = submatrix(grid, row, col, size);
	if (!sub)
		return (0); //error handling needs work since every nb is a possible outcome
	minor = determinant(sub);
	return (minor);
}