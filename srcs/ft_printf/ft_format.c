/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:30:51 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/04 17:33:27 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, const char format)
{
	int	count_chars;

	count_chars = 0;
	if (format == 'c')
		count_chars += ft_printchar(va_arg(*args, int));
	else if (format == 's')
		count_chars += ft_printstr(va_arg(*args, char *));
	else if (format == 'p')
		count_chars += ft_printptr(va_arg(*args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count_chars += ft_printnbr(va_arg(*args, int));
	else if (format == 'u')
		count_chars += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		count_chars += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		count_chars += ft_print_percent();
	else
	{
		count_chars = 1;
		write(1, &format, 1);
	}
	if (count_chars < 0)
		return (-1);
	return (count_chars);
}
