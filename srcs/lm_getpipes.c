/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_getpipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:20:16 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 07:48:41 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_room	*lm_room_exist(char *name_room, t_data *data)
{
	int		hash;
	t_room	*current_room;

	hash = hachage(name_room, ft_strlen(name_room));
	current_room = data->hashtable[hash];
	while (current_room != NULL &&
		ft_strcmp(current_room->name, name_room) != 0)
		current_room = current_room->next;
	return (current_room);
}

int				lm_link_room(t_room *room_0, t_room *room_1)
{
	t_links	*new_link;
	t_links	*current_link;

	current_link = room_0->links;
	while (current_link != NULL &&
		ft_strcmp(current_link->name, room_1->name) != 0)
		current_link = current_link->next;
	if (current_link == NULL)
	{
		if (!(new_link = (t_links *)ft_memalloc(sizeof(t_links))))
			return (-1);
		new_link->name = room_1->name;
		new_link->hash = hachage(new_link->name, ft_strlen(new_link->name));
		new_link->next = room_0->links;
		room_0->links = new_link;
		new_link->room = room_1;
	}
	return (0);
}

int				lm_make_links(t_data *data, char **room_to_link, char **line)
{
	t_room	*room_0;
	t_room	*room_1;

	room_0 = lm_room_exist(room_to_link[0], data);
	room_1 = lm_room_exist(room_to_link[1], data);
	if (room_0 && room_1)
	{
		if (lm_link_room(room_0, room_1) == -1 ||
			lm_link_room(room_1, room_0) == -1)
		{
			lm_free_exit(data, line);
			lm_free_str(room_to_link);
			//free tous les links; //ne pas continuer malloc error;
			exit(EXIT_FAILURE);
		}
	}
	else
		return (-1);
	return (0);
}

int				lm_get_pipe(t_data *data, char **line)
{
	int		i;
	char	**room_to_link;
	char	*correct_line;

	i = ft_countnchar(*line, '-');
	if (i == 1)
	{
		correct_line = ft_strsub(*line, 0, ft_strlen(*line) - 1);
		room_to_link = ft_strsplit(correct_line, '-');
		free(correct_line);
		if (room_to_link[0] && room_to_link[1])
		{
			if (lm_make_links(data, room_to_link, line) == -1)
				return (-1);
		}
		else
		{
			lm_free_str(room_to_link);
			return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

void			lm_pipe(t_data *data, char **line)
{
	char	*tmp;

	if (*line == NULL)
	{
		//free
		exit(EXIT_FAILURE);
	}
	if (!(*line[0] == '#'))
	{
		if (lm_get_pipe(data, line) == -1)
			lm_free_exit(data, line);
	}
	free(*line);
	while (get_next_line(0, line) == 1)
	{
		tmp = data->line;
		data->line = ft_strjoin(data->line, *line);
		free(tmp);
		if (!(*line[0] == '#'))
			if (lm_get_pipe(data, line) == -1)
				break ;
		free(*line);
	}
	free(*line);
}
