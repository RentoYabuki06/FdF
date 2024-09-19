/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:43:58 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 15:15:53 by yabukirento      ###   ########.fr       */
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
	if (argc != 2)
		ft_error_exit("Usage: ./fdf [map]");
	ft_initcheck_file(argv[1]);
}