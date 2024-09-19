/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:41:21 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 16:47:06 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static uint32_t	ft_add_diff_color(uint32_t color, t_line prm, size_t count)
{
	uint32_t	rtn_color;
	uint32_t	next_r;
	uint32_t	next_g;
	uint32_t	next_b;

	if (prm.dred == 0 && prm.dgreen == 0 && prm.dblue)
		return (color);
	rtn_color = 0x000000;
	next_r = ((color >> 16) & 0xFF);
	next_g = ((color >> 8) & 0xFF);
	next_b = (color & 0xFF);
	rtn_color += (next_r << 16) + ((int)(prm.dred * (int)count) << 16);
	rtn_color += (next_g << 8) + ((int)(prm.dgreen * (int)count) << 8);
	rtn_color += (next_b) + (int)(prm.dblue * (int)count);
	return (rtn_color);
}

static void	ft_drawing(t_fdf *fdf, t_line prm, size_t i, size_t next)
{
	t_point		*point;
	size_t		count;
	uint32_t	set_color;

	point = fdf->map->point3d;
	count = 0;
	set_color = point[i].color;
	while (count <= prm.lenght)
	{
		if (point[i].color != point[i + next].color)
			set_color = ft_add_diff_color(point[i].color, prm, count);
		ft_put_on_pixel(fdf, round(prm.px), round(prm.py), set_color);
		if (point[i + next].screen_x < point[i].screen_x)
			prm.px -= prm.dx;
		else
			prm.px += prm.dx;
		if (point[i + next].screen_y < point[i].screen_y)
			prm.py -= prm.dy;
		else
			prm.py += prm.dy;
		count++;
	}
}

static void	ft_set_color_dif(t_point *point, t_line *prm, size_t i, size_t next)
{
	uint32_t	color_s;
	uint32_t	color_e;

	color_s = point[i].color;
	color_e = point[i + next].color;
	if (color_s == color_e)
	{
		prm->dred = 0;
		prm->dgreen = 0;
		prm->dblue = 0;
		return ;
	}
	prm->lred = (((color_e >> 16) & 0xFF) - ((color_s >> 16) & 0xFF));
	prm->lgreen = (((color_e >> 8) & 0xFF) - ((color_s >> 8) & 0xFF));
	prm->lblue = (((color_e) & 0xFF) - ((color_s) & 0xFF));
	prm->dred = (double)prm->lred / (double)prm->lenght;
	prm->dgreen = (double)prm->lgreen / (double)prm->lenght;
	prm->dblue = (double)prm->lblue / (double)prm->lenght;
}

// 描画開始点、線の長さ、変化率、色の差を取得
static void	ft_set_params(t_fdf *fdf, t_point *point, size_t i, size_t next)
{
	t_line	prm;

	prm.px = point[i].screen_x;
	prm.py = point[i].screen_y;
	prm.lx = ft_abs(point[i + next].screen_x - point[i].screen_x);
	prm.ly = ft_abs(point[i + next].screen_y - point[i].screen_y);
	if (prm.lx > prm.ly)
		prm.lenght = prm.lx;
	else
		prm.lenght = prm.ly;
	prm.dx = prm.lx / prm.lenght;
	prm.dy = prm.ly / prm.lenght;
	if (point[i].color != point[i + next].color)
		ft_set_color_dif(point, &prm, i, next);
	ft_drawing(fdf, prm, i, next);
}

void	ft_draw_line(t_fdf *fdf)
{
	size_t	i;
	t_map	*map;
	t_point	*point;

	i = 0;
	map = fdf->map;
	point = fdf->map->point3d;
	while (i < (map->height * map->width) - 1)
	{
		if (point[i].y == point[i + 1].y && i < (map->width * map->height) - 1)
			ft_set_params(fdf, point, i, 1);
		if ((i) < map->width * (map->height - 1))
			ft_set_params(fdf, point, i, map->width);
		i++;
	}
}