/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:44:31 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/15 20:54:40 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	ft_sort(t_stack	**stack_a, t_stack **stack_b)
{
	int	t_node;

	t_node = ft_node_size(*stack_a);
	ft_putnbr_fd(t_node,1);
	if( (ft_sorted(stack_a)) && (t_node == 3 || t_node == 2))
		ft_sort_two_three(stack_a);
	else if((ft_sorted(stack_a)) && (t_node == 4 || t_node == 5))
		ft_sort_four_five(stack_a, stack_b);
	else if ((ft_sorted(stack_a)) && t_node > 5)
	{
		ft_radix(stack_a, stack_b);
	}
	else
		{
			ft_free_lst(stack_a);
			ft_free_lst(stack_b);
		}
}

void	ft_sort_two_three(t_stack **stack_a)
{
	int		big;
	
	big = ft_find_big(*stack_a);
	if((*stack_a)->std == big)
		ft_ra(stack_a);
	else if((*stack_a)->next->std == big)
		ft_rra(stack_a);
	if((*stack_a)->std > (*stack_a)->next->std)
		ft_swap(stack_a);
}

void	ft_sort_four_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_node_size(*stack_a);
	
	while(size)
	{
		if((*stack_a)->std == 1 || (*stack_a)->std == 2)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		size--;
	}
	ft_sort_two_three(stack_a);
	ft_pa(stack_b,stack_a);
	ft_pa(stack_b,stack_a);
	if((*stack_a)->std > (*stack_a)->next->std)
		ft_sa(stack_a);
}

int	ft_bits(int	max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return(max_bits);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	column;
	int	row;
	int	big_size;
	int	big_nb;
	int size;
	
	big_nb = ft_find_big(*stack_a);
	big_size = ft_bits(big_nb);
	column = 0;
	while(column < big_size)
	{
		size = ft_node_size(*stack_a);
		row = 0;
		while(row < size)
		{
			if(((*stack_a)->std >> column)&1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			row++;
		}
		while(*stack_b)
		{
			ft_pa(stack_b, stack_a);
		}
		column++;
	}
}
