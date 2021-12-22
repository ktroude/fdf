/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:54:01 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 16:54:28 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_map_data(int fd)
{
	char	*str;
	char	*gnl;

	str = NULL;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		str = ft_strjoin_v2(str, gnl);
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (str);
}

int	count_line_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**get_tab_char(int fd)
{
	char	**tab;
	char	*data;

	data = get_map_data(fd);
	tab = ft_split(data, '\n');
	return (tab);
}
