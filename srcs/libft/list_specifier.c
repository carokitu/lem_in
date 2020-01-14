/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:03:31 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/03 19:06:08 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		list_specifier(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "diouxXscpf";
	while (flags[i] != c && flags[i] != '|')
		i++;
	if (flags[i] == c && c != '|')
		return (1);
	return (0);
}
