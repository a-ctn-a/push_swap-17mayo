/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:52:04 by anzarago          #+#    #+#             */
/*   Updated: 2025/01/10 16:02:15 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar (va_arg (args, int)));
	else if (type == 's')
		return (ft_putstr (va_arg (args, char *)));
	else if (type == 'i' || type == 'd')
		return (ft_putnbr (va_arg (args, int)));
	else if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'p')
		return (ft_putptr (va_arg (args, uintptr_t)));
	else if (type == 'u')
		return (ft_unsignbr (va_arg (args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex (va_arg (args, int), type));
	return (1);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_type (s[i], args);
		}
		else
		{
			ft_putchar (s[i]);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}

// int main ()
// {
// 	ft_printf("hola %u", -1);
// 	return(0);
// }