/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:40:12 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/14 18:46:09 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(char **argv, int argc )
{
	int	i;
	int	j;

	if (argc == 2)
		i = 0;
	if (argc > 2)
		i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if ((ft_strcmp(argv[i], argv[j]) == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_num(char **argv, int argc)
{
	int	i;

	if (argc == 2)
		i = 0;
	if (argc > 2)
		i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (0);
		if (!(ft_str_digit(argv[i])))
			return (0);
		i++;
	}
	return (1);
}
int	ft_check_arg(char **argv, int argc)
{
	int	i;
	
	i = 0;
	if(argc > 2)
		i = -1;
	while(argv[i])
		i++;
	if (i < 2)
		return(0);
	return(1);
}


int	ft_check_limit(char **argv, int argc)
{
	int	i;
	
	if (argc == 2)
		i = 0;
	if (argc > 2)
		i = 1;
	while (argv[i])
	{
		if ((ft_atoll(argv[i]) > INT_MAX) || (ft_atoll(argv[i]) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checker(char **argv, int argc)
{
	if (!(ft_check_num(argv, argc)))
	{	
		return (0);
	}
	if (!ft_check_double(argv, argc))
	{		
		return (0);
	}
	if (!ft_check_limit(argv, argc))
	{	
		return (0);
	}
	if (!ft_check_arg(argv, argc))
	{	
		return (0);
	}
	return (1);
}
