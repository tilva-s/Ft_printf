/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:19:22 by tiago             #+#    #+#             */
/*   Updated: 2023/10/31 12:30:38 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int     ft_check_condition(char str, va_list ptr, int count);
int    ft_putchar(char c);
int     ft_putnbr(int n);
int	ft_count_len(int n);
int     ft_putstr(char *str);

int     ft_count_len(int n)
{
        int     div;
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

int	ft_putstr(char *str)
{
	int	count;
	
	count = 0;
	while (str[count] != '\0')
		count += ft_putchar(str[count]);
	return (count);
}

int     ft_putnbr(int n)
{
        int     i;
	int	count;
	
	count = ft_count_len(n);
        i = 0;
        if (n < 0)
        {
                if (n == INT_MIN)
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
                ft_putchar(n + 48);
        return (count);
}
