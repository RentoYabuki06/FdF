/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:53:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 13:43:24 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n, bool is_negative)
{
	size_t	len;

	len = 0;
	if (is_negative == true)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_num_to_str(size_t len, int num, bool is_negative)
{
	char	*ans;

	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		len--;
		ans[len] = num % 10 + '0';
		num /= 10;
	}
	if (is_negative)
		ans[0] = '-';
	return (ans);
}

char	*ft_itoa(int num)
{
	size_t		len;
	bool		is_negative;

	if (num == 0)
		return (ft_strdup("0"));
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = false;
	if (num < 0)
	{
		is_negative = true;
		num *= -1;
	}
	len = ft_numlen(num, is_negative);
	return (ft_num_to_str(len, num, is_negative));
}
