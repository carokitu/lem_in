/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:07:49 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/29 11:20:56 by cde-moul         ###   ########.fr       */
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

/* 
void			lm_free_path(t_path *last)
{
	t_path		*current;
	t_path		*tmp;

	current = last;
	while (current->previous)
	{
		tmp = current;
		if (tmp->next && tmp->next != tmp->previous)
		{
			ft_printf("ici on free -> %s\n", tmp->next->room->name);
			free(tmp->next);
		}
		current = current->previous;
		if (current->next != tmp)
		{
			ft_printf("free de : %s\n", tmp->room->name);
			free(tmp);
		}
	}
	ft_printf("free de : %s\n", current->room->name);
	free(current);
}
*/
void		lm_free_path(t_path *last)
{
	t_path	*current;
	t_path	*previous;

	current = last;
	while (current)
	{
		previous = current->previous;
		if (current->next)
			free(current->next);
		if (previous == NULL || previous == NULL || previous->next != current)
			free(current);
		current = previous;
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
	lm_free_path(data->last);
	lm_free_t_best(data->best);
	while (++i < 8111)
	{
		if (data->hashtable[i])
			lm_free_rooms(data->hashtable[i]);
	}
	free(data);
	exit(EXIT_SUCCESS);
}
