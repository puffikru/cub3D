/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:37:45 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 12:37:50 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void		check_line_map(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i] >= '0' && line[i] <= '2') &&
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
		line[i] != 'W' && line[i] != '\t')
			error("Unknown symbol on map line");
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
		line[i] == 'W')
		{
			ptr->p->dir_pl = line[i];
			ptr->c->pos_player++;
		}
		i++;
	}
}
