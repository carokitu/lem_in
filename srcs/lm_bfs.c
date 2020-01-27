/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:56:20 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 08:29:37 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		lm_add_links(t_path *current_path, t_path **last, t_data *data)
{
	t_links	*current_link;

	current_link = NULL;
	if (current_path->room)
		current_link = current_path->room->links;
	while (current_link != NULL)
	{
		if (lm_flux_gestion(current_link, data, last, current_path) == 1)
			return (1);
		current_link = current_link->next;
	}
	return (0);
}

void		lm_edmonds_karp(t_data *data)
{
	t_path	*current_path;
	char	*name;
	char	*name_previous;
	t_links	*current_link;

	current_path = data->last;
	while (current_path->previous)
	{
		name = current_path->room->name;
		name_previous = current_path->previous->room->name;
		current_link = current_path->room->links;
		while (ft_strcmp(current_link->name, name_previous) != 0)
			current_link = current_link->next;
		current_link->flux = current_link->flux == 0 ? -1 : 0;
		current_link = current_path->previous->room->links;
		while (ft_strcmp(current_link->name, name) != 0)
			current_link = current_link->next;
		current_link->flux = current_link->flux == 0 ? 1 : 0;
		current_path = current_path->previous;
	}
}

static int	lm_real_bfs(t_data *data, t_path *current_path, t_path *last)
{
	if (!(current_path = (t_path *)ft_memalloc(sizeof(t_path))))
		lm_exit(data, "Malloc Error\n");
	current_path->room = data->start;
	data->start->pass = data->pass;
	last = current_path;
	if (lm_add_links(current_path, &last, data) == 1)
	{
		data->last = last;
		lm_edmonds_karp(data);
		return (1);
	}
	while (current_path != NULL)
	{
		if (lm_add_links(current_path, &last, data) == 1)
		{
			data->last = last;
			lm_edmonds_karp(data);
			return (1);
		}
		current_path = current_path->next;
	}
	return (0);
}

int			lm_bfs(t_data *data)
{
	t_path	*current_path;
	t_path	*last;

	data->pass += 1;
	current_path = NULL;
	last = NULL;
	if (data->start && data->end)
	{
		if (lm_real_bfs(data, current_path, last) == 1)
			return (1);
	}
	else
		lm_exit(data, "USAGE: You need an end and a start\n");
	return (0);
}
