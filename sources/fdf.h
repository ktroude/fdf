/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:19:14 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 18:06:51 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_tab
{
	char	**tab_char;
	char	**tab_split;
	int		**tab_int;
	int		x;
	int		y_char;
	int		y_int;
	int		y_s;

}	t_tab;

typedef struct s_tab1
{
	int	x;
	int	y;
	int	**tab;
}	t_tab1;

typedef struct s_tab2
{
	int	a;
	int	b;
	int	m;
}	t_tab2;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_brasenjb
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	xincr;
	int	yincr;
	int	err;
	int	i;
}	t_brasenjb;

char	*get_map_data(int fd);
int		count_line_tab(char **tab);
char	**get_tab_char(int fd);
int		**do_tab_int_things(t_tab tab, int ligne);
int		**get_tab_int(int fd);
t_point	define_pt_s(t_tab2 d, t_tab1 t);
t_point	define_pt_e(t_tab2 d, t_tab1 t);
t_point	define_pt_e_y(t_tab2 d, t_tab1 t);
void	brasenham(t_vars vars, t_point s, t_point e, int color);
void	put_pix_tab_int(t_vars vars, int fd, int color);
int		ft_close(int keycode, t_vars *vars);
int		ft_close_x(t_vars *vars);

#endif
