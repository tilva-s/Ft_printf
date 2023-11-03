/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:19:22 by tiago             #+#    #+#             */
/*   Updated: 2023/11/03 17:19:47 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
*/
/*
int     ft_check_condition(char str, va_list ptr, int count);
int    ft_putchar(char c, int count);
int     ft_putnbr(int n);
int	ft_count_len(int n);
int     ft_putstr(char *str);
int     ft_count_len2(unsigned int n);
*/

int	ft_count_len(int n)
{
	int	div;
	int	aux;

	div = 0;
	aux = n;
	while (aux)
	{
		aux = aux / 10;
		div++;
	}
	if (n < 0)
		return (div + 1);
	else
		return (div);
}

int	ft_count_len2(unsigned int n)
{
	int			div;
	unsigned int	aux;

	div = 0;
	aux = n;
	while (aux)
	{
		aux = aux / 10;
		div++;
	}
	return (div);
}

int	ft_putunsigned(unsigned int number, int flag)
{
	int	count;

	if (flag == 1)
		count = ft_count_len2(number);
	if (number >= 10)
		ft_putunsigned(number / 10, 0);
	ft_putchar((number % 10) + 48, 0);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count += ft_putchar(str[count], 0);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = ft_count_len(n);
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write (1, "-2147483648", 11);
			return (11);
		}
		ft_putchar('-', 0);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48, 0);
	}
	else
		ft_putchar(n + 48, 0);
	return (count);
}
