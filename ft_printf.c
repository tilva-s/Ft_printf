/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:43:12 by tsilva-s          #+#    #+#             */
/*   Updated: 2023/10/28 17:19:54 by tsilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

char	*ft_verify(char type);
void    ft_call(char *type, char tmp);
void    ft_putchar_fd(char c);

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	ptr;
	char* type;
	char	tmp;

	i = 0;
	type = NULL;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			type = ft_verify(str[i + 1]);
			if (type != NULL)
			{
				tmp = va_arg(ptr, int);
				ft_call(type, tmp);
				i++;
				i++;
			}
			if (str[i] == '\0')
				break ;
		}
		ft_putchar_fd(str[i++]);
	}
	va_end(ptr);
	return (i);
}

char 	*ft_verify(char type)
{
	if (type == 'c')
		return ("char");
	else if( type == 'p')
		return ("int");
	return (NULL);
}

void	ft_call(char *type, char tmp)
{
	if (strcmp(type, "char") == 0)
			ft_putchar_fd(tmp);
}

void    ft_putchar_fd(char c)
{
        write(1, &c, sizeof(c));
}

int	main()
{
	//char	*str[10] = "Ola";

	ft_printf("OLa %c", 't' );
}	
