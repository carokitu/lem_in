/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:35:27 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/22 12:13:15 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		lm_print_rooms(t_data *data)
{
	int		i;
	t_room	*current;
	t_links	*links;

	i = -1;
	ft_printf("\n\n");
	while (++i < 8111)
	{
		current = data->hashtable[i];
		if (current != NULL)
		{
			ft_printf("hashtable n*%d :\n", i);
			while (current != NULL)
			{
				ft_printf("\033[0;32mname = %s\033[0m\n", current->name);
				links = current->links;
				if (links != NULL)
					ft_printf("\033[1;34mlinks :\033[0m\n");
				while (links != NULL)
				{
					ft_printf("\t%s\n", links->name);
					links = links->next;
				}
				current = current->next;
			}
			ft_printf("\n");
		}
	}
}

void	lm_print_path(t_path *path)
{
	t_links *links;
	while (path != NULL)
	{
		ft_printf("room = %s\n", path->room->name);
		links = path->room->links;
		while (links)
		{
			ft_printf("\033[1;34mlinks = %s\033[0m\n", links->name);
			ft_printf("\033[1;60mflux = %d\033[0m\n", links->flux);
			links = links->next;
		}
		ft_printf("\n");
		path = path->previous;
	}
}

void		lm_print_best(t_best *best)
{
	t_ants_info *start;
	t_ants_info *current;
	int		i;

	i = 0;
	start = best->infos;
	ft_printf("nombre de mouvements total :  %d\n", best->total_moves);
	while (start)
	{
		ft_printf("CHEMIN NUMERO %d\n", i);
		ft_printf("nombre de mouvements : %d\n", start->moves);
		i++;
		current = start;
		while (current)
		{
			if (current->next != NULL)
				ft_printf("%s --> ", current->room->name);
			if (current->next == NULL)
				ft_printf("%s\n", current->room->name);
			current = current->next;
		}
		start = start->next_start;
	}
	ft_printf("\n");
}
