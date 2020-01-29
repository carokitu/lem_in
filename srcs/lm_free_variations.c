/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_variations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:31:47 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/29 14:04:10 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				lm_free_str(char **str)
{
	int	i;

	i = -1;
	if (str != NULL)
	{
		while (str[++i])
			free(str[i]);
	}
	free(str);
	return (0);
}

void			lm_print_exit(t_data *data, char *print)
{
	ft_printf("%s", print);
	lm_exit(data);
}

void			lm_free_exit(t_data *data, char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	lm_print_exit(data, "ERROR\n");
}
