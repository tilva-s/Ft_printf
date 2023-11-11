/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:43:12 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/04 14:47:14 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ptr;
	int			count;

	if (!str)
		return (-1);
	count = 0;
	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != '\0')
				count += ft_check_condition(str[i], ptr);
		}
		else
			count += ft_putchar(str[i], 0);
		i++;
	}
	va_end(ptr);
	return (count);
}

int	ft_check_condition(char str, va_list ptr)
{
	if (str == 'c')
		return (ft_putchar(va_arg(ptr, int), 0));
	else if (str == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (str == 'd')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (str == '%')
		return (ft_putchar(str, 0));
	else if (str == 'u')
		return (ft_putunsigned(va_arg(ptr, unsigned int), 1));
	else if (str == 'x')
		return (ft_puthexa_low(va_arg(ptr, unsigned int)));
	else if (str == 'X')
		return (ft_puthexa_high(va_arg(ptr, unsigned int)));
	else if (str == 'p')
		return (ft_putmemory(va_arg(ptr, void *)));
	return (0);
}

int	ft_putchar(char c, int count)
{
	count++;
	write (1, &c, 1);
	return (count);
}
