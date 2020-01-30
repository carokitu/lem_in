/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_flux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:28:10 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/29 12:04:05 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lm_get_flux(t_path *current_path)
{
	t_links		*tmp_links;

	if (current_path->previous)
	{
		if (current_path->previous->room)
			tmp_links = current_path->previous->room->links;
	}
	if (current_path->previous)
	{
		if (current_path->previous->room)
		{
			while (tmp_links)
			{
				if (ft_strcmp(tmp_links->name, current_path->room->name) == 0)
					return (tmp_links->flux);
				tmp_links = tmp_links->next;
			}
		}
	}
	return (0);
}

t_links		*lm_flux_dependance(t_links *current_link, int a, int b)
{
	t_links	*link_save;

	link_save = current_link;
	if (current_link->flux == a)
	{
		while (current_link)
		{
			if (current_link->flux == b)
			{
				link_save = current_link;
				return (link_save);
			}
			current_link = current_link->next;
		}
	}
	return (link_save);
}

int			lm_flux_gestion(t_links *current_link, t_data *data,
			t_path *current_path)
{
	int		flux;
	t_path	*new_path;

	if (current_link->room->pass != data->pass && current_link->flux != 1)
	{
		flux = lm_get_flux(current_path);
		if (flux == -1)
			current_link = lm_flux_dependance(current_link, -1, 0);
		else
			current_link = lm_flux_dependance(current_link, 0, -1);
		current_link->room->pass = data->pass;
		if (!(new_path = (t_path *)ft_memalloc(sizeof(t_path))))
			lm_print_exit(data, "ERROR : Malloc\n");
		new_path->room = current_link->room;
		new_path->previous = current_path;
		data->last->next = new_path;
		data->last = new_path;
	}
	if (ft_strcmp(current_link->name, data->end->name) == 0 &&
		current_link->flux != 1)
		return (1);
	else if (current_link->flux == -1)
		return (2);
	current_link = current_link->next;
	return (0);
}
