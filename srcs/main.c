/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:43:58 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 16:56:12 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_error_exit("Usage: ./fdf [map]");
	ft_initcheck_file(argv[1]);
	fdf = ft_init_fdf(&argv[1]);
	fdf->map = ft_init_map();
	ft_read_map(argv[1], fdf->map);
	ft_conv_iso(fdf->map);
	ft_draw_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, ft_close_esc, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close_win, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}