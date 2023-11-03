/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:01:17 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/03 17:19:30 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
*/
/*
int     ft_check_condition(char str, va_list ptr, int count);
int    ft_putchar(char c, int count);
int     ft_putnbr(int n);
int     ft_count_len(int n);
int     ft_putstr(char *str);
int     ft_count_len2(unsigned int n);
int     ft_puthexa_low(unsigned int num);
int     ft_puthexa_high(unsigned int num);
int     ft_putmemory(void *mem);
int	ft_puthexa(unsigned long long int mem);
*/

int	ft_puthexa_low(unsigned int num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (num < 16)
		return (count = ft_putchar(base[num], count));
	else
	{
		count = ft_puthexa_low(num / 16);
		return (count = ft_putchar(base[num % 16], count));
	}
}

int	ft_puthexa_high(unsigned int num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (num < 16)
		return (count = ft_putchar(base[num], count));
	else
	{
		count = ft_puthexa_high(num / 16);
		return (count = ft_putchar(base[num % 16], count));
	}
}

int	ft_putmemory(void *mem)
{
	int			count;
	unsigned long long int	num;

	num = (unsigned long long int ) mem;
	ft_putchar(0 + 48, 0);
	ft_putchar('x', 1);
	count = ft_puthexa(num);
	return (count + 2);
}

int	ft_puthexa(unsigned long long int num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (num < 16)
		return (count = ft_putchar(base[num], count));
	else
	{
		count = ft_puthexa(num / 16);
		return (count = ft_putchar(base[num % 16], count));
	}
}
