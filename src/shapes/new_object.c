/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_object.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/19 13:06:16 by marieke       #+#    #+#                 */
/*   Updated: 2024/12/09 13:35:21 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <free.h>
#include <libft.h>

void	add_object_to_list(t_object **head, t_object *new)
{
	t_object	*cur;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	add_shape_to_object(t_object *object, void *shape)
{
	if (object->type == CYLINDER)
		object->cylinder = (t_cylinder *)shape;
	else if (object->type == SPHERE)
		object->sphere = (t_sphere *)shape;
	else if (object->type == PLANE)
		object->plane = (t_plane *)shape;
}

t_object	*new_object(int type, t_material m, t_matrix transform, void *shape)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	ft_bzero(object, sizeof(t_object));
	object->type = type;
	object->material = m;
	object->transformation = transform;
	if (!is_identity_matrix(transform, 4))
		object->inverted = invert_matrix(transform, 4);
	add_shape_to_object(object, shape);
	object->next = NULL;
	return (object);
}
