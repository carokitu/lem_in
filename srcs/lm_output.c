/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:57:19 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/23 11:01:12 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	lm_print(t_data *data, t_ants_info *start)
{
		t_ants_info	*current;
		int			save;
		int			save_next;

		save = 0;
	//	ft_printf("NB ANTS %d\n", start->nb_ants);
		if (start->nb_ants-- > 0 && data->ants != 0)
		{
				data->ants--;
				save = start->ants_in;
				data->ant_regis = data->ant_regis + 1;
				start->ants_in = data->ant_regis;
				ft_printf("L%d-%s ", start->ants_in, start->room->name);
		}
		else
		{
			save = start->ants_in;
			start->ants_in = 0;
		}
		current = start->next;
		while (current)
		{
				save_next = current->ants_in;
				current->ants_in = save;
				save = save_next;
				save_next = 0;
				if (current->ants_in != 0)
					ft_printf("L%d-%s ", current->ants_in, current->room->name);
				current = current->next;
		}
}

void	lm_output(t_data *data)
{
		t_ants_info		*current_start;

		ft_printf("%s\n", data->line);
		while (data->best->nb_steps != 0)
		{
				current_start = data->best->infos;
				data->best->nb_steps--;
				while (current_start) 
				{
						lm_print(data, current_start);
						current_start = current_start->next_start;
				}
				ft_printf("\n");
		}
}
