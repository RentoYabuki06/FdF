/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:01:44 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 17:05:31 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_get_height(char *filename)
{
	int		fd;
	size_t	height;
	char	*line;

	height = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_exit("failed open. (at get_height)\n");
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	if (close(fd) == -1)
		ft_error_exit("failed close. (at get_height)\n");
	return (height);
}

static int	ft_get_width(char *filename)
{
	int		fd;
	size_t	width;
	char	*line;

	width = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_exit("failed open. (at get_width)\n");
	line = get_next_line(fd);
	width = ft_count_col(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	if (close(fd) == -1)
		ft_error_exit("failed close. (at get_width)\n");
	return (width);
}

static void	ft_store_value(char *line, t_map *map, int y)
{
	static int	s_idx;
	size_t			x;

	x = 0;
	while(x < map->width)
	{
		while (*line == ' ')
			line++;
		map->point3d[s_idx].x = (double)x;
		map->point3d[s_idx].y = (double)y;
		map->point3d[s_idx].z = (double)ft_atoi(line);
		while (*line != ' ' && *line != ',' && *line != '\0' && *line != '\n') 
			line++;
		if (*line == ',')
			map->point3d[s_idx].color = ft_hextoi(line);
		else
			map->point3d[s_idx].color = 0xFFFFFF;
		while (*line != ' ' && *line != '\0' && *line != '\n')
			line++;
		s_idx++;
		x++;
	}
}

void	ft_read_map(char *filename, t_map *map)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	map->height = ft_get_height(filename);
	map->width = ft_get_width(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_exit("failed open. (at read_map)\n");
	map->point3d = malloc(sizeof(t_point) * map->height * map->width);
	if (map->point3d == NULL)
		ft_error_exit("failed malloc. (at read_map)\n");
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_store_value(line, map, y);
		free(line);
		y++;
	}
	if (close(fd) == -1)
		ft_error_exit("failed close. (at read_map)\n");
}
