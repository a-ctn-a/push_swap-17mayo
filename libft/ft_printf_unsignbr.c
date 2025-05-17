/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:19:04 by anzarago          #+#    #+#             */
/*   Updated: 2025/01/10 16:11:35 by anzarago         ###   ########.fr       */
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
		n = n / 10;
		len ++;
	}
	return (len);
}

int	ft_unsignbr(unsigned int n)
{
	unsigned int	mod;
	unsigned int	div;
	char			a;
	int				len;

	len = ft_len(n);
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	mod = n % 10;
	div = n / 10;
	if (div > 0)
		ft_unsignbr(div);
	a = mod + '0';
	write (1, &a, 1);
	return (len);
}
