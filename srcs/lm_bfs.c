/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:56:20 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/15 18:12:48 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


// Si ca marche pas envoyer addresses t_path

int		lm_add_links(t_path *current_path, t_path *last, t_data *data)
{
	t_links	*current_link;
	t_path	*new_path;

	current_link = current_path->room->links;
	while (current_link != NULL)
	{
		if (current_link->room->pass != data->pass)
		{
			current_link->room->pass = data->pass;
			if (!(new_path = (t_path *)ft_memalloc(sizeof(t_path))))
				//free tout et exit
			new_path->room = current_link->room;
			new_path->previous = current_path;
			last->next = new_path;
			last = new_path;
		}
		if (ft_strcmp(current_link->name, data->end->name) == 0)
			return (1);
		current_link = current_link->next;
	}
	return (0);
}


void		lm_bfs_test(t_data *data)
{
	t_path	*current_path;
	t_path	*last;

	data->pass += 1;
	if (data->start && data->end)
	{
		if (!(current_path = (t_path *)ft_memalloc(sizeof(t_path))))
			//free tout et exit
		current_path->room = data->start;
		data->start->pass = data->pass;
		last = current_path;
		if (lm_add_links(current_path, last, data) == 1)
			return;// (lm_next);
		while (current_path != NULL)
		{
			if (lm_add_links(current_path, last, data) == 1)
				return;// (lm_next);
			current_path = current_path->next;
		}
	}
}
