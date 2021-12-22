/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:55:07 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 18:15:38 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pix_tab_int(t_vars vars, int fd, int color)
{
	t_tab1	t;
	t_tab2	d;
	t_point	s;
	t_point	e;

	d.m = 5;
	t.x = 0;
	t.y = 0;
	d.a = 900;
	d.b = 100;
	t.tab = get_tab_int(fd);
	while (t.tab[t.y + 1][0] != -2147483648)
	{
		s = define_pt_s(d, t);
		e = define_pt_e(d, t);
		brasenham(vars, s, e, color);
		s = define_pt_s(d, t);
		e = define_pt_e_y(d, t);
		brasenham(vars, s, e, color);
		t.x++;
		if (t.tab[t.y][t.x + 1] == -2147483648)
		{
			s = define_pt_s(d, t);
			e = define_pt_e_y(d, t);
			brasenham(vars, s, e, color);
			t.x = 0;
			free(t.tab[t.y]);
			t.y++;
		}
	}
	while (t.tab[t.y][t.x + 1] != -2147483648)
	{
		s = define_pt_s(d, t);
		e = define_pt_e(d, t);
		brasenham(vars, s, e, color);
		t.x++;
	}

	free(t.tab[t.y]);
	free(t.tab);
	t.tab = NULL;
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	int		fd;
	int		color;

	if (argc != 2)
	{
		printf("error frerow\n");
		return (0);
	}
	color = 0x00FF0000;
	fd = open(argv[1], O_RDONLY);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_pix_tab_int(vars, fd, color);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_hook(vars.win, 17, 1L<<0, ft_close_x, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	free(vars.win);
	free(img.img);
	free(img.addr);
}
