/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:45:53 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 16:33:41 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long a)
{
	int	len_str;

	len_str = 0;
	if (0 <= write(1, "0x", 2))
		len_str += 2;
	else
		return (-1);
	if (a == 0)
	{
		if (0 <= write(1, "0", 1))
			len_str++;
		else
			return (-1);
	}
	else
	{
		if (0 > ft_put_hex(a, 1))
			return (-1);
		len_str += ft_hex_len(a);
	}
	return (len_str);
}
