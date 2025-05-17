/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:40:36 by anzarago          #+#    #+#             */
/*   Updated: 2025/01/10 16:13:47 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len ++;
	}
	return (len);
}

int	ft_puthex(int n, char format)
{
	unsigned int	mod;
	unsigned int	div;
	char			a;
	int				len;
	unsigned int	num;

	a = 0;
	num = (unsigned int)n;
	len = ft_len(num);
	mod = num % 16;
	div = num / 16;
	if (div > 0)
		ft_puthex(div, format);
	if (mod < 10)
		a = mod + '0';
	else if (format == 'x')
		a = mod - 10 + 'a';
	else if (format == 'X')
		a = mod - 10 + 'A';
	write (1, &a, 1);
	return (len);
}
