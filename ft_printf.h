/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:13:32 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/11/03 17:30:37 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_check_condition(char str, va_list ptr, int count);
int	ft_putchar(char c, int count);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int number, int flag);
int	ft_puthexa_low(unsigned int num);
int	ft_puthexa_high(unsigned int num);
int	ft_putmemory(void *mem);
int	ft_count_len(int n);
int	ft_count_len2(unsigned int n);
int	ft_puthexa(unsigned long long int mem);

#endif
