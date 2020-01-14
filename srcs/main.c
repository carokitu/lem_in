/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:36:07 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/14 17:25:38 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_nb_ants(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		if (!(*line[0] == '#' && (!(*line[1]) || (!(*line[1] != '#' )))))
		{
			if (ft_isanint(*line) == 1)
			{
				data->ants = ft_atoi(*line);
				break ;
			}
			else
			{
				ft_printf("ERROR\n");
				free(line);
				free(data);
				exit(EXIT_FAILURE);
			}
	}
	if (data->ants <= 0)
	{
		ft_printf("ERROR\n");
		free(line);
		free(data);
		exit(EXIT_FAILURE);
	}
}

static void		lm_checkorders(t_data *data, char **line)
{
	if (ft_strcmp(*line, "##start") == 0)
		lm_getstart(data, line);
	else if (ft_strcmp(*line, "##end") == 0)
		lm_getend(data, line);
	else
	{
		free(line);
		if (data->start)
			free(data->start;
		if(data->end)
			free(data->end);
		free(data);
		//FREE HASHTABLE ?
		exit(EXIT_FAILURE);
	}
}

static void		lm_room(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		if (!(*line[0] == '#' && (!(*line[1]) || (!(*line[1] != '#' )))))
		{
			if (*line[0] == '#' && *line[1] == '#')
				lm_checkorders(data, line);
			else
				lm_get_room(data, line);
		}
	}
}

static void		lm_parsing(t_data *data)
{
	char	**line;

	if (!(line = (char **)ft_memalloc(sizeof(char *))))
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	lm_nb_ants(data, line);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	lm_parsing(data);
}
