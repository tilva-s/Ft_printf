/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:19:22 by tiago             #+#    #+#             */
/*   Updated: 2023/11/07 19:11:51 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
	if (n < 0 || n == 0)
		return (div + 1);
	else
		return (div);
}

int	ft_count_len2(unsigned int n)
{
	int				div;
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

	count = 0;
	if (flag == 1)
	{
		if (number == 0)
			count = 1;
		else
			count = ft_count_len2(number);
	}
	if (number >= 10)
		ft_putunsigned(number / 10, 0);
	ft_putchar((number % 10) + 48, 0);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
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
