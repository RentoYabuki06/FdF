/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:00 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 17:13:24 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int a)
{
	int		count;
	char	*tmp;

	tmp = ft_printf_itoa(a);
	if (!tmp)
		return (-1);
	count = ft_printstr(tmp);
	free(tmp);
	return (count);
}
