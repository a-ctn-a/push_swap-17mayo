/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:45:23 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/15 20:04:18 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int argc, char **argv)
{
	if(argc == 2)
		ft_free(argv);
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	ft_out(int argc, char **argv)
{
	if(argc == 2)
		ft_free(argv);
	exit(0);
}

int	ft_sorted(t_stack **stack)
{
	t_stack	*temp;
	
	temp = *stack;
	while(temp && temp->next)
	{
		if(temp->std > temp->next->std)
			return(1);
		temp = temp->next;
	}
	return(0);
}

int	ft_find_big(t_stack *stack)
{
	int		big_std;
	t_stack	*temp;

	big_std = 0;
	temp = stack;
	while(temp && temp->next)
	{
		if(temp->std > big_std)
			big_std = temp->std;
		temp = temp->next;
	}
	return(big_std);
	
}