/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:25 by yabukirento       #+#    #+#             */
/*   Updated: 2024/07/14 15:06:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_tmp;
	int		len_total_len;
	va_list	args;

	i = 0;
	len_total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len_tmp = ft_format(&args, format[++i]);
		else
			len_tmp = ft_printchar(format[i]);
		if (len_tmp >= 0)
			len_total_len += len_tmp;
		else
			return (-1);
		i++;
	}
	va_end(args);
	return (len_total_len);
}
