/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:28 by spenning          #+#    #+#             */
/*   Updated: 2024/07/06 15:56:41 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	index;
	char				*cptr;

	cptr = (char *)s;
	index = 0;
	while (index < n)
	{
		cptr[index] = (const int)c;
		index++;
	}
	return (cptr);
}
