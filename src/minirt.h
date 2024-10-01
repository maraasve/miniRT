/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:28:02 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/01 18:03:53 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "tuples.h"

# define WIDTH 20
# define HEIGHT 10

typedef struct s_data
{
	int		screen_width;
	int		screen_height;
	char	*addr;
	int		line_length;
	int		bpp;
}t_data;

#endif
