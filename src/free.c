/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:43:48 by marieke           #+#    #+#             */
/*   Updated: 2024/10/22 17:55:59 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	free_mlx(t_data *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->image);
	mlx_destroy_display(data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
}

void	free_matrix(float **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_intersection(t_intersection **intersection)
{
	t_intersection *cur;
	t_intersection *next;

	if (!intersection || !*intersection)
		return ;
	cur = (*intersection);
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	(*intersection) = NULL;
}

void	free_spheres(t_sphere **head)
{
	t_sphere	*cur;
	t_sphere	*next;

	if (!head || !*head)
		return ;
	cur = (*head);
	while (cur)
	{
		next = cur->next;
		free_matrix(cur->base->transformation.grid, 4);
		free(cur->base);
		free(cur);
		cur = next;
	}
	(*head) = NULL;
}