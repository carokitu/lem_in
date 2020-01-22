/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:14:37 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/22 17:12:35 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void		lm_compare(t_data *data)
{
	if (data->best == NULL)
		data->best = data->challenger;
	else
	{
		// changer comparaison
		//ft_printf("data->best->nb_steps = %d\ndata->challenger->nb_steps = %d\n",data->best->nb_steps, data->challenger->nb_steps);
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
