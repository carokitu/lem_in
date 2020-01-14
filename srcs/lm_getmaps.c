/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_getmaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:06:53 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/14 17:26:19 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		hachage(char *name, size_t l)
{
    size_t  i;
    size_t  tot;

    i = 0;
    tot = 0;
    if (!name)
        return (0);
    while (i < l)
	{
		tot += name[i] * ft_puissance(256, l - i - 1);
		i++;
	}
    tot = tot % 8111;
    return ((int)tot);
}

char	**lm_check_room(t_data *data, char **line)
{
	char	**room;
	t_room	*name;
	int		hash;

	room = ft_strsplit(*line, ' ');
	if (room[0] && room[1] && room[2] && !room[3])
	{
		if (ft_isanint(room[1]) && ft_isanint(room[2]))
		{
			hash = hachage(room[0], ft_strlen(room[0]));
			if (data->hashtable[hash] != NULL)
			{
				name = data->hashtable[hash];
				while (name != NULL)
				{
					if (ft_strcmp(name->name, room[0]) == 0)
					{
						ft_printf("ERROR\n");
						free(line);
						// free(room) (toutes les cases);
						free(data)
						exit(EXIT_FAILURE);
					}
					name = name->next;
				}
			}
		}
	}
	return (room);
}

void	lm_get_room(t_data *data, char **line)
{
	char	**room;
	t_room	*new_room;
	t_room	*current_room;
	int		hash;

	room = lm_check_room(data, line);
	hash = hachage(room[0], ft_strlen(room[0]));
	if (!(new_room = (t_room *)ft_memalloc(sizeof(t_room))))
		//FREE hashtable / line / data
		exit(EXIT_FAILURE);
	current_room = data->hashtable[hash];
	if (current_room == NULL)
		current_room = new_room;
	else
	{
		new_room->next = current_room;
		data->hashtable[hash] = new_room;
	}
	new_room->name = ft_strdup(room[0]);
	new_room->coord_x = ft_atoi(room[1]);
	new_room->coord_y = ft_atoi(room[2]);
	//free(room);

}

void	lm_getstart(t_data *data, char **line)
{
	char	**room;
	t_room	*new_room;
	t_room	*current_room;
	int		hash;

	room = lm_check_room(data, line);
	hash = hachage(room[0], ft_strlen(room[0]));
	if (data->start != NULL || !(new_room = (t_room *)ft_memalloc(sizeof(t_room))))
		//FREE hashtable / line / data
		exit(EXIT_FAILURE);
	current_room = data->hashtable[hash];
	if (current_room == NULL)
		current_room = new_room;
	else
	{
		new_room->next = current_room;
		data->hashtable[hash] = new_room;
	}
	new_room->name = ft_strdup(room[0]);
	new_room->coord_x = ft_atoi(room[1]);
	new_room->coord_y = ft_atoi(room[2]);
	data->start = new_room;
	//free(room);
}

void    lm_getend(t_data *data, char **line)
{
	char	**room;
	t_room	*new_room;
	t_room	*current_room;
	int		hash;

	room = lm_check_room(data, line);
	hash = hachage(room[0], ft_strlen(room[0]));
	if (data->end != NULL || !(new_room = (t_room *)ft_memalloc(sizeof(t_room))))
		//FREE hashtable / line / data
		exit(EXIT_FAILURE);
	current_room = data->hashtable[hash];
	if (current_room == NULL)
		current_room = new_room;
	else
	{
		new_room->next = current_room;
		data->hashtable[hash] = new_room;
	}
	new_room->name = ft_strdup(room[0]);
	new_room->coord_x = ft_atoi(room[1]);
	new_room->coord_y = ft_atoi(room[2]);
	data->end = new_room;
	//free(room);
}

