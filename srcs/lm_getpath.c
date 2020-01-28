/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:02:09 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/28 11:20:03 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				lm_nb_path(t_data *data)
{
	int		i;
	t_links	*link;

	i = 0;
	link = data->start->links;
	while (link)
	{
		if (link->flux == 1)
			i++;
		link = link->next;
	}
	data->challenger->nb_path = i;
}

static int			lm_lenght_course(t_room *current_room,
			t_data *data, t_links *count_links, t_ants_info *current)
{
	int			i;
	t_ants_info	*next;

	i = 1;
	while (current_room != data->end)
	{
		count_links = current_room->links;
		while (count_links && count_links->flux != 1)
			count_links = count_links->next;
		i++;
		current_room = count_links->room;
		count_links = current_room->links;
		if (!(next = (t_ants_info *)ft_memalloc(sizeof(t_ants_info))))
			lm_print_exit(data, "Malloc Error\n");
		next->room = current_room;
		current->next = next;
		current = current->next;
	}
	return (i);
}

int					lm_path_lenght(t_room *current_room, t_data *data)
{
	int			i;
	t_links		*count_links;
	t_ants_info	*start;
	t_ants_info	*current;

	i = 1;
	if (data->challenger)
		start = data->challenger->infos;
	else
	{
		lm_print_exit(data, "dont get this error\n");
		exit(EXIT_SUCCESS);
	}
	while (start->next_start)
		start = start->next_start;
	count_links = NULL;
	current = start;
	i = lm_lenght_course(current_room, data, count_links, current);
	start->moves = i;
	return (i);
}

static void			lm_get_challenger(t_data *data, t_room *current_room,
		t_ants_info *next_start, t_ants_info **current_start)
{
	if (data->challenger == NULL)
	{
		if ((!(data->challenger = (t_best *)ft_memalloc(sizeof(t_best))))
		|| !(*current_start = (t_ants_info *)ft_memalloc(sizeof(t_ants_info))))
			lm_print_exit(data, "Malloc Error\n");
		(*current_start)->room = current_room;
		data->challenger->infos = *current_start;
	}
	else
	{
		if (!(next_start = (t_ants_info *)ft_memalloc(sizeof(t_ants_info))))
			lm_print_exit(data, "Malloc Error\n");
		next_start->room = current_room;
		(*current_start)->next_start = next_start;
		(*current_start) = (*current_start)->next_start;
	}
}

void				lm_total_path_lenght(t_data *data)
{
	int				i;
	t_room			*current_room;
	t_links			*current_link;
	t_ants_info		*current_start;
	t_ants_info		*next_start;

	i = 0;
	next_start = NULL;
	current_start = NULL;
	current_room = data->start;
	current_link = current_room->links;
	while (current_link)
	{
		if (current_link->flux == 1)
		{
			current_room = current_link->room;
			lm_get_challenger(data, current_room, next_start, &current_start);
			i += lm_path_lenght(current_room, data);
		}
		current_link = current_link->next;
	}
	data->challenger->total_moves = i;
}
