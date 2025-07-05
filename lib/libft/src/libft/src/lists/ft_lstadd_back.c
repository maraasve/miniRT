/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:31:33 by spenning          #+#    #+#             */
/*   Updated: 2024/07/06 15:37:56 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*last;

	last = ft_lstlast((*lst));
	if (last == NULL)
		(*lst) = new;
	else
		last->next = new;
}
