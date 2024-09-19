/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:43:58 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 15:33:18 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_error_exit("Usage: ./fdf [map]");
	ft_initcheck_file(argv[1]);
	fdf = ft_init_fdf(argv[1]);
	fdf->map = ft_init_map();
	ft_read_map(argv[1], fdf->map);
	ft_init_mlx(fdf);
	ft_draw_map(fdf);
	mlx_hook(fdf->win, 2, 0, ft_key_press, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}