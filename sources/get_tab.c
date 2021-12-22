/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:30:08 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 16:53:16 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**do_tab_int_things(t_tab tab, int ligne)
{
	while (tab.tab_char[tab.y_char])
	{
		tab.tab_split = ft_split(tab.tab_char[tab.y_char], ' ');
		ligne = count_line_tab(tab.tab_split);
		tab.tab_int[tab.y_int] = malloc(sizeof(int) * (ligne + 1));
		while (tab.tab_split[tab.y_s])
		{
			tab.tab_int[tab.y_int][tab.x] = ft_atoi(tab.tab_split[tab.y_s]);
			tab.x++;
			free(tab.tab_split[tab.y_s]);
			tab.y_s++;
		}
		free(tab.tab_split[tab.y_s]);
		free(tab.tab_split);
		tab.tab_int[tab.y_int][tab.x] = -2147483648;
		tab.y_int++;
		tab.x = 0;
		tab.y_s = 0;
		tab.y_char++;
	}
	free(tab.tab_char);
	tab.tab_int[tab.y_int] = malloc(sizeof(int) * 2);
	tab.tab_int[tab.y_int][0] = -2147483648;
	tab.tab_int[tab.y_int][1] = -2147483648;
	return (tab.tab_int);
}

int	**get_tab_int(int fd)
{
	int		ligne;
	t_tab	tab;

	tab.tab_char = get_tab_char(fd);
	tab.x = 0;
	tab.y_char = 0;
	tab.y_s = 0;
	tab.y_int = 0;
	ligne = count_line_tab(tab.tab_char);
	tab.tab_int = malloc(sizeof(int *) * (ligne + 1));
	tab.tab_int = do_tab_int_things(tab, ligne);
	return (tab.tab_int);
}
