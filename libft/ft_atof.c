/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:23:32 by anzarago          #+#    #+#             */
/*   Updated: 2025/04/30 19:16:04 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	process_digit(char c, double *result, double *div, int *decimal)
{
	*result = *result * 10 + (c - '0');
	if (*decimal)
		*div *= 10;
}

static int	parse_sign_and_skip(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *nptr)
{
	int		i;
	int		sign;
	double	result;
	double	div;
	int		decimal;

	sign = 1;
	result = 0.0;
	div = 1.0;
	decimal = 0;
	i = parse_sign_and_skip(nptr, &sign);
	while (nptr[i])
	{
		if (nptr[i] == '.' && !decimal)
			decimal = 1;
		else if (nptr[i] >= '0' && nptr[i] <= '9')
			process_digit(nptr[i], &result, &div, &decimal);
		else
			break ;
		i++;
	}
	return (sign * (result / div));
}
