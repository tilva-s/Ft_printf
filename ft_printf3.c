/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:01:17 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/01 17:29:14 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int     ft_check_condition(char str, va_list ptr, int count);
int    ft_putchar(char c);
int     ft_putnbr(int n);
int     ft_count_len(int n);
int     ft_putstr(char *str);
int     ft_count_len2(unsigned int n);
int     ft_puthexa_low(unsigned int num);

int     ft_puthexa_low(unsigned int num)
{
	char		*base;
	unsigned int	quotient;
	int		count;

	base = "0123456789abcdef";
	if (num < 16)
		return (ft_putchar(base[num]));
	else
	{
		count = ft_puthexa_low(num / 16);
		return (count + ft_puthexa_low(num / 16));
	}
}
