/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <tsilva-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:43:12 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/03 17:22:29 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
*/
/*
int	ft_check_condition(char str, va_list ptr, int count);
int	ft_putchar(char c, int count);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int, int flag);
int	ft_puthexa_low(unsigned int num);
int	ft_puthexa_high(unsigned int num);
int	ft_putmemory(void *mem);
*/
int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ptr;
	int			count;

	count = 0;
	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_check_condition(str[i + 1], ptr, count);
			i = i + 2;
		}
		else if (str[i] != '\0')
		{
			count += ft_putchar(str[i], 0);
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

int	ft_check_condition(char str, va_list ptr, int count)
{
	if (str == 'c')
		count = ft_putchar(va_arg(ptr, int), 0);
	if (str == 'i')
		count = ft_putnbr(va_arg(ptr, int));
	if (str == 's')
		count = ft_putstr(va_arg(ptr, char *));
	if (str == 'd')
		count = ft_putnbr(va_arg(ptr, int));
	if (str == '%')
		count = ft_putchar(str, 0);
	if (str == 'u')
		count = ft_putunsigned(va_arg(ptr, unsigned int), 1);
	if (str == 'x')
		count = ft_puthexa_low(va_arg(ptr, unsigned int));
	if (str == 'X')
		count = ft_puthexa_high(va_arg(ptr, unsigned int));
	if (str == 'p')
		count = ft_putmemory(va_arg(ptr, void *));
	return (count);
}

int	ft_putchar(char c, int count)
{
	count++;
	write (1,&c, 1);
	return (count);
}
/*int	main(void)
{
	int	count;
	int	count2;
	char	*str = "askda";

	count = ft_printf("Ola eu sou o %i e tenho %c esta %% str %s, teste %u e outro %u mais um %x e maiuscula hexa %X e memoria %p", -2, 'T', "", -24, 21312, 54400, 54400, str);
	printf("\n%d\n", count);
	count2 = printf("Ola eu sou o %i e tenho %c esta %% str %s, teste %u e outro %u mais um %x e maiuscula hexa %X e memoria %p", -2, 'T', "", -24, 21312, 54400, 54400, str);
	printf("\n%d", count2);
	return (0);
}*/
