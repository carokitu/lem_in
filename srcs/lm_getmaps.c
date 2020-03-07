/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_getmaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:06:53 by cde-moul          #+#    #+#             */
/*   Updated: 2020/02/03 12:19:22 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		**lm_getroom(t_data *data, char **line)
{
	char	**room;

	room = lm_check_room(data, line);
	if (room == NULL)
	{
		lm_free_str(room);
		lm_free_exit(data, line);
	}
	return (room);
}

t_room			*lm_fillroom(t_data *data, char **room, char **line, int hash)
{
	t_room	*new_room;
	t_room	*current_room;

	if (!(new_room = (t_room *)ft_memalloc(sizeof(t_room))))
	{
		lm_free_str(room);
		lm_free_exit(data, line);
	}
	if (!(new_room->name = ft_strdup(room[0])))
	{
		lm_free_str(room);
		free(new_room);
		lm_free_exit(data, line);
	}
	new_room->coord_x = ft_atoi(room[1]);
	new_room->coord_y = ft_atoi(room[2]);
	current_room = data->hashtable[hash];
	if (current_room == NULL)
		current_room = new_room;
	else
		new_room->next = current_room;
	data->hashtable[hash] = new_room;
	return (new_room);
}

void			lm_getend(t_data *data, char **line)
{
	char	**room;
	int		hash;

	free(*line);
	while (get_next_line(0, line) == 1)
	{
		lm_get_line(data, line);
		if ((*line)[0] == '#' && ((!((*line)[1])) ||
			(((*line)[1]) && ((*line)[1] != '#'))))
			free(*line);
		else if (ft_strcmp(*line, "##start\n") == 0 ||
				ft_strcmp(*line, "##end\n") == 0)
			lm_free_exit(data, line);
		else
			break ;
	}
	if ((*line) == NULL)
		lm_free_exit(data, line);
	room = lm_getroom(data, line);
	hash = hachage(room[0], ft_strlen(room[0]));
	if (data->end != NULL)
		lm_free_exit(data, line);
	data->end = lm_fillroom(data, room, line, hash);
	lm_free_str(room);
}

void			lm_getstart(t_data *data, char **line)
{
	char	**room;
	int		hash;

	free(*line);
	while (get_next_line(0, line) == 1)
	{
		lm_get_line(data, line);
		if ((*line)[0] == '#' && ((!((*line)[1])) ||
			(((*line)[1]) && ((*line)[1] != '#'))))
			free(*line);
		else if (ft_strcmp(*line, "##start\n") == 0 ||
				ft_strcmp(*line, "##end\n") == 0)
			lm_free_exit(data, line);
		else
			break ;
	}
	if ((*line) == NULL)
		lm_free_exit(data, line);
	room = lm_getroom(data, line);
	hash = hachage(room[0], ft_strlen(room[0]));
	if (data->start != NULL)
		lm_free_exit(data, line);
	data->start = lm_fillroom(data, room, line, hash);
	lm_free_str(room);
}
