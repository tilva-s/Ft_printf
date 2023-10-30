/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:43:12 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/10/30 21:59:26 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_check_condition(char str, va_list ptr, int count);
int    ft_putchar(char c);
int	ft_putnbr(int n);

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	ptr;
	int	count;

	count = 0;
	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_check_condition(str[i + 1], ptr, count);
			i= i + 2;
		}
		else if (str[i] != '\0')
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

int	ft_check_condition(char str, va_list ptr, int count)
{
	if (str == 'c')
		count = ft_putchar(va_arg(ptr, int));
	if (str == 'd')
		count = ft_putnbr(va_arg(ptr, int));
		return (count);
}

int	ft_count_len(int n)
{
	int	div;

	div = 0;

	while (n / 10)
		div++;
	return (div + 1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write (1, "-2147483648", 11); 
			return (11);
		}
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
	return (ft_count_len(n));
}

int	ft_putchar(char c)
{
	write (1 , &c, 1);
	return (1);
}

int	main(void)
{
	int	count;
	
	count = ft_printf("Ola eu sou o %d", 214748364);
	printf("\n%d", count);
	return (0);
}
