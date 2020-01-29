/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:07:49 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/29 12:17:12 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_free_rooms(t_room *current)
{
	t_room		*to_free;
	t_links		*previous;

	while (current)
	{
		if (current->name)
		{
			free(current->name);
			current->name = NULL;
		}
		if (current->links)
		{
			while (current->links)
			{
				previous = current->links;
				current->links = current->links->next;
				free(previous);
				previous = NULL;
			}
		}
		to_free = current;
		current = current->next;
		free(to_free);
	}
}

void			lm_free_path(t_path *last)
{
	t_path	*current;
	t_path	*tmp;

	current = last;
	while (current->previous)
		current = current->previous;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void			lm_free_t_best(t_best *best)
{
	t_ants_info	*current;
	t_ants_info	*current_start;
	t_ants_info	*tmp;
	t_ants_info	*tmp_start;

	if (best == NULL)
		return ;
	current_start = best->infos;
	while (current_start)
	{
		tmp_start = current_start;
		current = current_start->next;
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		current_start = current_start->next_start;
		free(tmp_start);
	}
	free(best);
}

void			lm_exit(t_data *data)
{
	int		i;

	i = -1;
	if (data->line)
		free(data->line);
	if (data->last)
		lm_free_path(data->last);
	if (data->best)
		lm_free_t_best(data->best);
	if (data->challenger)
		lm_free_t_best(data->challenger);
	while (++i < 8111)
	{
		if (data->hashtable[i])
			lm_free_rooms(data->hashtable[i]);
	}
	free(data);
	exit(EXIT_SUCCESS);
}
