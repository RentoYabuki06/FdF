/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:30:50 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/21 17:07:06 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_trans_to_iso(t_map *map)
{
	size_t	i;
	t_point	*point;

	point = map->point3d;
	i = 0;
	while (i < (map->height * map->width))
	{
		point[i].iso_x = (point[i].x - point[i].y) * COS_30;
		point[i].iso_y = \
		-(point[i].z) + (point[i].x + point[i].y) * SIN_30;
		i++;
	}
}

static void	ft_get_iso_max(t_map *map)
{
	t_point	*point;
	size_t	i;

	point = map->point3d;
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->max_ix < point[i].iso_x)
			map->max_ix = point[i].iso_x;
		if (map->max_iy < point[i].iso_y)
			map->max_iy = point[i].iso_y;
		if (point[i].iso_x < map->min_ix)
			map->min_ix = point[i].iso_x;
		if (point[i].iso_y < map->min_iy)
			map->min_iy = point[i].iso_y;
		i++;
	}
	map->d_ix = map->max_ix + fabs(map->min_ix);
	map->d_iy = map->max_iy + fabs(map->min_iy);
}

void	ft_conv_iso(t_map *map)
{
	size_t	i;
	t_point	*point;
	double	scale;

	i = 0;
	point = map->point3d;
	ft_trans_to_iso(map);
	ft_get_iso_max(map);
	if (RATE <= 1)
		scale = (map->d_ix);
	else
		scale = (map->d_iy) * 1.75;
	while (i < (map->height * map->width))
	{
		point[i].screen_x = \
		(((point[i].iso_x + fabs(map->min_ix)) * (WIDTH / scale)));
		point[i].screen_y = \
		((point[i].iso_y + fabs(map->min_iy)) * (HEIGHT / scale)) * RATE + 50;
		i++;
	}
}
