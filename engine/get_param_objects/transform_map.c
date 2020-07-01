/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 07:45:16 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/01 07:45:18 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static int		check_size_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

static char		**check_new(char **new)
{
	int i;
	int j;

	i = 0;
	while (new[i])
	{
		j = 0;
		while (new[i][j])
		{
			if (new[i][j] != ' ' && !(new[i][j] >= '0' && new[i][j] <= '2')
			&& new[i][j] != 'N' && new[i][j] != 'S' && new[i][j] != 'E' &&
			new[i][j] != 'W' && new[i][j] != '\t')
				new[i][j] = ' ';
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	return (new);
}

static char		**push_param_map(char **new, char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			new[j][i] = arr[i][j];
			j++;
		}
		i++;
	}
	return (check_new(new));
}

char			**transform_split_map(char **arr)
{
	int		i;
	int		size_vert;
	int		size_gorz;
	char	**new_arr;

	size_gorz = check_size_arr(arr);
	size_vert = ft_strlen(arr[0]);
	if (!(new_arr = (char **)malloc(sizeof(char *) * (size_vert + 1))))
		return (NULL);
	i = 0;
	while (i < size_vert)
	{
		if (!(new_arr[i] = (char *)malloc(sizeof(char) * (size_gorz))))
		{
			while (new_arr[--i])
				free(new_arr[i]);
			free(new_arr);
		}
		i++;
	}
	new_arr[size_vert] = NULL;
	return (push_param_map(new_arr, arr));
}
