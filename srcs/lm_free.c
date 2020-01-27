/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:07:49 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 08:41:03 by fgaribot         ###   ########.fr       */
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
	if (data->line)
		free(data->line);
	while (++i < 8111)
	{
		if (data->hashtable[i])
			lm_free_rooms(data->hashtable[i]);
	}
	free(data);
	ft_printf("ERROR\n");
	exit(EXIT_SUCCESS);
}

void		lm_free_path(t_data *data)
{
	t_path	*current;
	t_path	*tmp;

	current = data->last;
	if (current)
	{
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		current = data->last;
		while (current)
		{
			tmp = current->previous;
			free(current);
			current = tmp;
		}
		free(data->last);
	}
}

void		lm_exit(t_data *data, char *print)
{
	int		i;

	i = -1;
	if (data->line)
		free(data->line);
	while (++i < 8111)
	{
		if (data->hashtable[i])
			lm_free_rooms(data->hashtable[i]);
	}
	lm_free_path(data);
	free(data);
	ft_printf("%s", print);
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
