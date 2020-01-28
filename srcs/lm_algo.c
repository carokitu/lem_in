/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:45:44 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/28 12:20:38 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lm_algo(t_data *data)
{
	while (lm_bfs(data) == 1)
	{
		lm_total_path_lenght(data);
		lm_nb_path(data);
		lm_total_moves(data);
		lm_compare(data);
		if (data->last)
		{
			lm_free_path(data->last);
			data->last = NULL;
		}
	}
}
