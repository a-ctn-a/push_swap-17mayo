/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:49:34 by anzarago          #+#    #+#             */
/*   Updated: 2025/01/10 16:07:44 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		mod;
	int		div;
	char	a;
	int		len;

	len = ft_len(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
	}
	mod = n % 10;
	div = n / 10;
	if (div > 0)
		ft_putnbr(div);
	a = mod + '0';
	write (1, &a, 1);
	return (len);
}
