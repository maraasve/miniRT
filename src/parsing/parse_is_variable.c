/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_is_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:57:38 by spenning          #+#    #+#             */
/*   Updated: 2025/07/05 12:18:10 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

int	parse_isint(char *num, int *i)
{
	int	start;

	start = *i;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (num[*i] != ' ' && num[*i] != '\n')
		return (0);
	if (ft_strncmp(num, "2147483647", *i - start) < 0)
		return (0);
	return (1);
}

int	parse_iscoordinates(char *coor, int *i)
{
	int	index;
	int	delim;

	index = 0;
	delim = ',';
	while (coor && index < 3)
	{
		if (index == 2)
			delim = ' ';
		if (!parse_isfloat(coor, delim, i))
			return (0);
		if (coor[*i] == delim && index == 2)
			break ;
		*i += 1;
		index++;
	}
	return (1);
}

int	parse_isnormalvec(char *vec, int *i)
{
	int	index;
	int	start;
	int	col;
	int	delim;

	index = 0;
	delim = ',';
	while (vec && index < 3)
	{
		start = *i;
		if (index == 2)
			delim = ' ';
		if (!parse_isfloat(vec, delim, i))
			return (0);
		col = atofn(vec, *i - start);
		if (col < -1 || col > 1)
			return (0);
		*i += 1;
		index++;
	}
	return (1);
}
