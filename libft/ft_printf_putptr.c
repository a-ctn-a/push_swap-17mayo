/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:38:22 by anzarago          #+#    #+#             */
/*   Updated: 2025/01/10 16:18:51 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_printptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar((ptr - 10) + 'a');
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	len;

	if (ptr == 0)
		return (write (1, "(nil)", 5));
	else
	{
		len = 2;
		write (1, "0x", 2);
		ft_printptr(ptr);
		len += ft_len(ptr);
	}
	return (len);
}
