/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:43 by marieke           #+#    #+#             */
/*   Updated: 2024/10/22 17:19:13 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_object_base	*new_object_base(int type, t_matrix transformation)
{
	t_object_base	*new;

	new = malloc(sizeof(t_object_base));
	if (!new)
		return (NULL);
	new->type = type;
	new->transformation = transformation;
	new->next = NULL;
	return (new);
}

void	add_object_to_list(t_object_base **head, t_object_base *new)
{
	t_object_base	*current;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		new->next = NULL;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}

void	add_sphere_to_list(t_sphere **head, t_sphere *new)
{
	t_sphere	*current;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		new->next = NULL;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;	
}