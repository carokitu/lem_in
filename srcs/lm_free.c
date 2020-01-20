/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:07:49 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/20 13:38:56 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	lm_free_rooms(t_room *current)
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
	}
}

void		lm_free_exit(t_data *data, char **line)
{
	int	i;
	i = -1;
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	while (++i < 8111)
	{
		if (data->hashtable[i])
				lm_free_rooms(data->hashtable[i]);
	}
	free(data);
	ft_printf("ERROR\n");
	exit(EXIT_SUCCESS);
}

void		lm_free_str(char **str)
{
	int	i;

	i = -1;
	if (str != NULL)
	{
		while (str[++i])
			free(str[i]);
	}
	free(str);
}
