/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:11 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 16:54:35 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_printf_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_printchar(int a);
int		ft_printstr(const char *str);
int		ft_format(va_list *args, const char format);
int		ft_printf(const char *format, ...);
int		ft_print_percent(void);
int		ft_printptr(unsigned long long a);
int		ft_printnbr(int a);
int		ft_print_hex(unsigned int nbr, char format);
char	*ft_strdup(const char *src);
int		ft_print_unsigned(unsigned int a);
int		ft_put_hex(unsigned long long num, int is_lower);
int		ft_hex_len(unsigned long long num);

#endif