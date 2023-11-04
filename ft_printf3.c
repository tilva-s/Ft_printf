/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:01:17 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/04 13:23:08 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
	int					count;
	unsigned long long	num;

	if (mem == 0)
		return (write(1, "(nil)", 5));
	num = (unsigned long long) mem;
	ft_putchar(0 + 48, 0);
	ft_putchar('x', 1);
	count = ft_puthexa(num);
	return (count + 2);
}

int	ft_puthexa(unsigned long long num)
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
