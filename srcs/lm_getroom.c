/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_getroom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:46:44 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/27 15:10:57 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				hachage(char *name, size_t l)
{
	size_t		i;
	size_t		tot;

	i = 0;
	tot = 0;
	if (!name)
		return (0);
	while (i < l)
	{
		tot += name[i] * ft_recursive_power(256, l - i - 1);
		i++;
	}
	tot = tot % 8111;
	return ((int)tot);
}

static void		lm_hash(char **room, t_data *data, char **line)
{
	int			hash;
	t_room		*name;

	hash = hachage(room[0], ft_strlen(room[0]));
	if (data->hashtable[hash] != NULL)
	{
		name = data->hashtable[hash];
		while (name != NULL)
		{
			if (ft_strcmp(name->name, room[0]) == 0)
				lm_free_exit(data, line);
			name = name->next;
		}
	}
}

char			**lm_check_room(t_data *data, char **line)
{
	char		**room;

	if (!(room = ft_strsplit(*line, ' ')))
		lm_free_exit(data, line);
	if (room[0] && room[1] && room[2] && !room[3])
	{
		if (room[0][0] != 'L' && ft_isanint(room[1]) && ft_isanint(room[2]))
			lm_hash(room, data, line);
		else
		{
			lm_free_str(room);
			lm_free_exit(data, line);
		}
		return (room);
	}
	lm_free_str(room);
	return (NULL);
}

int				lm_get_room(t_data *data, char **line)
{
	char		**room;
	int			hash;

	room = lm_check_room(data, line);
	if (room == NULL)
		return (-1);
	hash = hachage(room[0], ft_strlen(room[0]));
	lm_fillroom(data, room, line, hash);
	lm_free_str(room);
//	free(*line);
	return (1);
}
