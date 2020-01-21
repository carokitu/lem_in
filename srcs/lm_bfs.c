/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:56:20 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/21 14:17:26 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


// Si ca marche pas envoyer addresses t_path

/*
int		lm_add_links(t_path **current_path, t_path **last, t_data *data)
{
	t_links	*current_link;
	t_path	*new_path;

	//ft_printf("current_path = %p\n", (*current_path)->room);
	current_link = NULL;
	if ((*current_path)->room)
		current_link = (*current_path)->room->links;
	while (current_link != NULL)
	{
		if (current_link->room->pass != data->pass)
		{
			current_link->room->pass = data->pass;
			if (!(new_path = (t_path *)ft_memalloc(sizeof(t_path))))
			{
				//free tout et exit
				ft_printf("MALLOC_ERROR\n");
				exit(EXIT_FAILURE);
			}
			new_path->room = current_link->room;
			new_path->previous = *current_path;
			(*last)->next = new_path;
			(*last) = new_path;
		}
		if (ft_strcmp(current_link->name, data->end->name) == 0)
			return (1);
		current_link = current_link->next;
	}
	return (0);
}*/

static int	lm_get_flux(t_path *current_path)
{	
	t_links		*tmp_links;

	
	if (current_path->previous)
		if (current_path->previous->room)
				tmp_links = current_path->previous->room->links;
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

int		lm_add_links(t_path *current_path, t_path **last, t_data *data)
{
	t_links	*current_link;
	t_links	*link_save;
	t_path	*new_path;
	int		flux;

	current_link = NULL;
	if (current_path->room)
		current_link = current_path->room->links;
	while (current_link != NULL)
	{
		if (current_link->room->pass != data->pass && current_link->flux != 1)
		{
			link_save = current_link;
			flux = lm_get_flux(current_path);
			if (flux == -1)	
			{
				if (current_link->flux == -1)
				{
					while (current_link)
					{
						if (current_link->flux == 0)
						{
								link_save = current_link;
							break;
						}
						current_link = current_link->next;
					}
				}
			}
			else if (flux == 0)
			{
				if (current_link->flux == 0)
				{
					while (current_link)
					{
						if (current_link->flux == -1)
						{
							link_save = current_link;
							break;
						}
						current_link = current_link->next;
					}
				}
			}
			current_link = link_save;	
			current_link->room->pass = data->pass;
			if (!(new_path = (t_path *)ft_memalloc(sizeof(t_path))))
			{
				//free tout et exit
				ft_printf("MALLOC_ERROR\n");
				exit(EXIT_FAILURE);
			}
			new_path->room = current_link->room;
			new_path->previous = current_path;
			(*last)->next = new_path;
			(*last) = new_path;
		}
		if (ft_strcmp(current_link->name, data->end->name) == 0 && current_link->flux != 1)
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
		if (current_link->flux == 0)
			current_link->flux = -1;
		else
			current_link->flux = 0;
		current_link = current_path->previous->room->links;
		while (ft_strcmp(current_link->name, name) != 0)
			current_link = current_link->next;
		if (current_link->flux == 0)
			current_link->flux = 1;
		else
			current_link->flux = 0;
		current_path = current_path->previous;
	}
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
		if (!(current_path = (t_path *)ft_memalloc(sizeof(t_path))))
		{
			//free tout et exit
			ft_printf("MALLOC_ERROR\n");
			exit(EXIT_FAILURE);
		}
		current_path->room = data->start;
		data->start->pass = data->pass;
		last = current_path;
		if (lm_add_links(current_path, &last, data) == 1)
		{
			data->last = last;
			lm_edmonds_karp(data);
			//lm_print_path(data->last);
			return (1);// (lm_next);
		}
		while (current_path != NULL)
		{
			if (lm_add_links(current_path, &last, data) == 1)
			{
				data->last = last;
				lm_edmonds_karp(data);
				//lm_print_path(data->last);
				return (1);// (lm_next);
			}
			current_path = current_path->next; 
			// ft_printf("current_path = %p\n", current_path);
		}
		ft_printf("\n");
	}
	return (0);
}
