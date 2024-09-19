/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:44:14 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 16:46:14 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}


uint32_t	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	put_on_pixel(t_fdf *env, int x, int y, uint32_t color)
{
	char	*dst;

	dst = env->addr + (y * env->size_line + x * (env->bpp / 8));
	*(uint32_t *)dst = color;
}

int	close_win(void *prm)
{
	t_fdf	*env;

	env = prm;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->map->point3d);
	free(env->map);
	free(env);
	exit (0);
}

int	close_esc(int keycode, t_fdf *env)
{
	if (!(keycode == 53))
		return (0);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->map->point3d);
	free(env->map);
	free(env);
	exit (0);
}
