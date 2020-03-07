/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:56:20 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/31 12:06:30 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				lm_add_links(t_path *current_path, t_data *data)
{
	t_links	*current_link;
	int		gestion;

	gestion = 0;
	current_link = NULL;
	if (current_path->room)
		current_link = current_path->room->links;
	while (current_link != NULL)
	{
		gestion = lm_flux_gestion(current_link, data, current_path);
		if (gestion == 1)
			return (1);
		else if (gestion == 2)
			break ;
		current_link = current_link->next;
	}
	return (0);
}

void			lm_edmonds_karp(t_data *data)
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

static int		lm_real_bfs(t_data *data, t_path *current_path)
{
	if (!(current_path = (t_path *)ft_memalloc(sizeof(t_path))))
		lm_print_exit(data, "ERROR\n");
	current_path->room = data->start;
	data->start->pass = data->pass;
	data->last = current_path;
	if (lm_add_links(current_path, data) == 1)
	{
		lm_edmonds_karp(data);
		return (1);
	}
	while (current_path != NULL)
	{
		if (lm_add_links(current_path, data) == 1)
		{
			lm_edmonds_karp(data);
			return (1);
		}
		current_path = current_path->next;
	}
	return (0);
}

int				lm_bfs(t_data *data)
{
	t_path	*current_path;

	data->pass += 1;
	current_path = NULL;
	if (data->start && data->end)
	{
		if (lm_real_bfs(data, current_path) == 1)
			return (1);
	}
	else
		lm_print_exit(data, "ERROR\n");
	return (0);
}
