/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:14:37 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 08:49:08 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_get_line(t_data *data, char **line)
{
	char		*tmp;

	if (data->line == NULL)
	{
		if (!(data->line = ft_strdup(*line)))
			lm_free_exit(data, line);
	}
	else
	{
		tmp = data->line;
		if (!(data->line = ft_strjoin(data->line, *line)))
			lm_free_exit(data, line);
		free(tmp);
	}
}

static void		lm_free_worst(t_best *data)
{
	t_ants_info *start;
	t_ants_info *current;
	t_ants_info *next;
	t_ants_info *next_start;

	start = data->infos;
	while (start)
	{
		current = start->next;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		next_start = start->next_start;
		free(start);
		start = next_start;
	}
	free(data);
	data = NULL;
}

void			lm_compare(t_data *data)
{
	if (data->best == NULL)
		data->best = data->challenger;
	else
	{
		if (data->best->nb_steps < data->challenger->nb_steps)
			lm_free_worst(data->challenger);
		else
		{
			lm_free_worst(data->best);
			data->best = data->challenger;
		}
	}
	data->challenger = NULL;
}
