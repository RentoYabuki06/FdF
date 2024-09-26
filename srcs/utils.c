/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:44:14 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 14:54:01 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

uint32_t	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	ft_put_on_pixel(t_fdf *fdf, int x, int y, uint32_t color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->size_line + x * (fdf->bpp / 8));
	*(uint32_t *)dst = color;
}

int	ft_close_win(void *prm)
{
	t_fdf	*fdf;

	fdf = prm;
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->map->point3d);
	free(fdf->map);
	free(fdf);
	exit (EXIT_SUCCESS);
}

int	ft_close_esc(int keycode, t_fdf *fdf)
{
	if (!(keycode == 53))
		return (0);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->map->point3d);
	free(fdf->map);
	free(fdf);
	exit (EXIT_SUCCESS);
}
