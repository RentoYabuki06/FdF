/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:26:03 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 16:28:27 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_ishex(char c)
{
	if (('a' <= c && c <= 'f') || \
	('A' <= c && c <= 'F'))
		return (1);
	return (0);
}

static uint32_t	ft_hex_to_num(char c)
{
	uint32_t	num;

	num = 0;
	if (('a' <= c && c <= 'f'))
		num = c - 87;
	else if ('A' <= c && c <= 'F')
		num = c - 55;
	return (num);
}

static size_t	ft_len_to_space(char *str)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(str[len]) || ft_ishex(str[len]))
		len++;
	return (len);
}

uint32_t	ft_hextoi(char *str)
{
	uint32_t	num;
	size_t		base;
	size_t		pow;

	pow = 0;
	num = 0;
	if (str == NULL)
		return (0);
	while (*str != 'x' && *str != 'X')
		str++;
	str++;
	while (ft_isdigit(*str) || ft_ishex(*str))
	{
		pow = (len_to_space(str) - 1);
		base = 1;
		while (pow-- > 0)
			base = base * 16;
		if (ft_isdigit(*str))
			num += (*str - '0') * base;
		else if (ft_ishex(*str))
			num += ft_hex_to_num(*str) * base;
		str++;
	}
	return (num);
}
