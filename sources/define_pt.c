/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_pt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:23:23 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 18:24:30 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	define_pt_s(t_tab2 d, t_tab1 t)
{
	t_point	r;

	r.x = d.a + (t.x - t.y) * 2 * d.m;
	r.y = d.b + (t.x + t.y) * d.m - roundf(d.m * 0.5 * t.tab[t.y][t.x]);
	return (r);
}

t_point	define_pt_e(t_tab2 d, t_tab1 t)
{
	t_point	z;

	z.x = d.a + ((t.x + 1) - t.y) * 2 * d.m;
	z.y = d.b + ((t.x + 1) + t.y) * d.m
		- roundf(d.m * 0.5 * t.tab[t.y][t.x + 1]);
	return (z);
}

t_point	define_pt_e_y(t_tab2 d, t_tab1 t)
{
	t_point	r;

	r.x = d.a + (t.x - (t.y + 1)) * 2 * d.m;
	r.y = d.b + (t.x + (t.y + 1)) * d.m
		- roundf(d.m * 0.5 * t.tab[t.y + 1][t.x]);
	return (r);
}
