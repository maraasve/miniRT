/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:56:09 by spenning          #+#    #+#             */
/*   Updated: 2024/07/06 15:36:28 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function will accept a string and a function pointer.
// Then to each character of the string the function will be applied
// until we reach the null terminator of the string

#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;
	size_t			s_len;

	index = 0;
	s_len = ft_strlen((const char *)s);
	while (index < s_len)
	{
		f(index, s);
		s++;
		index++;
	}
	return ;
}
