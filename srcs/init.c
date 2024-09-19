/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:29:41 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 15:37:54 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_init_fdf(const char **argv)
{
	t_fdf	*fdf;
	char	*title;

	title = ft_strjoin("FDF - ", argv[1]);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		ft_error_and_exit("ERROR: Failed to allocate memory for fdf.\n");
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error_and_exit("ERROR: Failed to initialize mlx.\n");
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, title);
	if (!fdf->win)
		ft_error_and_exit("ERROR: Failed to create window.\n");
	free(title);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_error_and_exit("ERROR: Failed to create image.\n");
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->size_line), &(fdf->endian));
	fdf->map = NULL;
	return (fdf);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error_and_exit("ERROR: Failed to allocate memory for map.\n");
	map->height = 0;
	map->width = 0;
	map->point3d = NULL;
	map->max_ix = DBL_MIN;
	map->min_ix = DBL_MAX;
	map->max_iy = DBL_MIN;
	map->min_iy = DBL_MAX;
	return (map);
}
