/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:02:49 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 16:09:52 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_count_col(const char *line, char c)
{
	int		i;
	int		col_num;

	i = 0;
	col_num = 0;
	while (line[i])
	{
		if (line[i] != c)
		{
			col_num++;
			while (line[i] && line[i] != c)
				i++;
		}
		else
			i++;
	}
	return (col_num);
}

static int	ft_chk_color_num(char *line)
{
	int	i;

	i = 0;
	line++;
	if (line[0] != '0' || (line[1] != 'x' && line[1] != 'X'))
		ft_error_and_exit("ERROR: Invalid color value.\n");
	line = line + 2;
	while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && !('a' <= line[i] && line[i] <= 'f') && \
		!('A' <= line[i] && line[i] <= 'F'))
			ft_error_and_exit("ERROR: Wrong color value.(expect 0~9 or a~f)\n");
		i++;
	}
	if (6 < i)
		ft_error_and_exit("ERROR: Too many color value.\n");
	return (i + 3);
}


static void ft_initcheck_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '-' || line[i] == '+')
			i++;
		while (line[i] != ' ' && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == 0 && line[i] != '\n' && line[i] != '\0')
				ft_error_and_exit("ERROR: Value is invalid.(error at chk_num)\n");
			i++;
			if (line[i] == '\n' || line[i] == '\0')
				break ;
		}
		if (line[i] == ',')
		{
			if (line[i - 1] == ' ' || line[i + 1] == ' ')
				ft_error_and_exit("ERROR: Value is invalid.(error at chk_num)\n");
			i = i + ft_chk_color_num(&line[i]);
		}
	}
}


void	ft_initcheck_file(char *filename)
{
	int		fd;
	int		col_num;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error: Invalid file");
	line = get_next_line(fd);
	if (line == NULL)
		ft_error_exit("Error: Empty file");
	ft_initcheck_line(line);
	col_num = ft_count_col(line, ' ');
	free(line);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (col_num != ft_count_col(line, ' '))
			ft_error_exit("ERROR: The number of rows are not equal.\n");
		free(line);
	}
	if (close(fd) == -1)
		ft_error_exit("Error: File close error");
}
