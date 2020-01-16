/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:36:07 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/16 17:18:19 by cde-moul         ###   ########.fr       */
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
				ft_printf("ERROR_1\n");
				free(line);
				free(data);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (data->ants <= 0)
	{
		ft_printf("ERROR_2\n");
		free(line);
		free(data);
		exit(EXIT_FAILURE);
	}
}

static void		lm_checkorders(t_data *data, char **line)
{
	if (ft_strcmp(*line, "##start\n") == 0)
		lm_getstart(data, line);
	else if (ft_strcmp(*line, "##end\n") == 0)
		lm_getend(data, line);
	else
	{
		free(line);
		if (data->start)
			free(data->start);
		if(data->end)
			free(data->end);
		free(data);
		//FREE HASHTABLE ?
		ft_printf("ERROR_4");
		exit(EXIT_FAILURE);
	}
}

static void		lm_room(t_data *data, char **line)
{
	while (get_next_line(0, line) == 1)
	{
		if (!(*line[0] == '#'))
		{
			if (lm_get_room(data, line) == -1)
				return;
		}
		if ((*line)[0] == '#' && (*line)[1] && (*line)[1] == '#')
			lm_checkorders(data, line);
	}
}

static void		lm_parsing(t_data *data)
{
	char	*line;

	line = NULL;
	lm_nb_ants(data, &line);
	lm_room(data, &line);
	lm_pipe(data, &line);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	//pas sure du argv = NULL
	argv = NULL;
	if (argc != 1)
	{
		ft_printf("ERROR_3\n");
		return (1);
	}
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	lm_parsing(data);
}
