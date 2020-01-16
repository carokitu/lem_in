/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:35:27 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/16 17:05:00 by cde-moul         ###   ########.fr       */
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
	while (path != NULL)
	{
		ft_printf("room = %s\n", path->room->name);
		path = path->previous;
	}
	ft_printf("room = %p\n", path);
}
