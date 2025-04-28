/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:58:34 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 17:12:32 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_numlen(long long n)
{
	size_t	i;

	i = 1;
	n = n / 10;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_printf_itoa(int n)
{
	char		*ans;
	size_t		len;
	long long	num;

	num = n;
	len = ft_numlen(num);
	if (n < 0)
	{
		len++;
		num *= -1;
	}
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
	if (n < 0)
		ans[0] = '-';
	return (ans);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ans;
	size_t	len;

	len = ft_numlen(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		len--;
		ans[len] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}
