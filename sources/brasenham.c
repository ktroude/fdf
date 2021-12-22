/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:25:52 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 16:41:57 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	brasen_part1(t_vars vars, t_brasenjb b, int color)
{
	b.err = b.dx / 2;
	while (b.i < b.dx)
	{
		b.x += b.xincr;
		b.err += b.dy;
		if (b.err > b.dx)
		{
			b.err -= b.dx;
			b.y += b.yincr;
		}
		mlx_pixel_put(vars.mlx, vars.win, b.x, b.y, color);
		b.i++;
	}
}

void	brasen_part_2(t_vars vars, t_brasenjb b, int color)
{
	b.err = b.dy / 2;
	while (b.i < b.dy)
	{
		b.y += b.yincr;
		b.err += b.dx;
		if (b.err > b.dy)
		{
			b.err -= b.dy;
			b.x += b.xincr;
		}
		mlx_pixel_put(vars.mlx, vars.win, b.x, b.y, color);
		b.i++;
	}
}

void	brasenham(t_vars vars, t_point s, t_point e, int color)
{
	t_brasenjb	b;

	b.dx = abs(e.x - s.x);
	b.dy = abs(e.y - s.y);
	if (s.x < e.x)
		b.xincr = 1;
	else
		b.xincr = -1;
	if (s.y < e.y)
		b.yincr = 1;
	else
		b.yincr = -1;
	b.x = s.x;
	b.y = s.y;
	b.i = 0;
	if (b.dx > b.dy)
		brasen_part1(vars, b, color);
	else
		brasen_part_2(vars, b, color);
}
