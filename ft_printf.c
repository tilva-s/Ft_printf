/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:43:12 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/01 17:36:28 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_check_condition(char str, va_list ptr, int count);
int    ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int, int flag);
int	ft_puthexa_low(unsigned int num);

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
	if (str == 'i')
		count = ft_putnbr(va_arg(ptr, int));
	if (str == 's')
		count = ft_putstr(va_arg(ptr, char *));
	if (str == 'd')
		count = ft_putnbr(va_arg(ptr, int));
	if (str == '%')
		count = ft_putchar(str);
	if (str == 'u')
		count = ft_putunsigned(va_arg(ptr, unsigned int), 1);
	if (str == 'x')
		count = ft_puthexa_low(va_arg(ptr, unsigned int));
	return (count);
}

int	ft_putchar(char c)
{
	write (1 , &c, 1);
	return (1);
}

int	main(void)
{
	int	count;
	int	count2;

	count = ft_printf("Ola eu sou o %i e tenho %c esta %% str %s, teste %u e outro %u mais um %x", -2, 'T', "", -24, 21312, 42949);
	printf("\n%d\n", count);
	count2 = printf("Ola eu sou o %i e tenho %c esta %% str %s, teste %u e outro %u mais um %x", -2, 'T', "", -24, 21312, 42949);
	printf("\n%d", count2);
	return (0);
}
