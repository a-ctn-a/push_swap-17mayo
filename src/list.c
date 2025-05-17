/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:35:42 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/15 19:13:01 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_node_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_standarized(t_stack	*stack, int size)
{
	t_stack	*big;
	t_stack	*std_stack;

	while (size)
	{
		big = NULL;
		std_stack = stack;
		while (std_stack)
		{
			if ((std_stack->std == -1)
				&& (big == NULL || std_stack->value > big->value))
			{
				big = std_stack;
			}
			std_stack = std_stack->next;
		}
		if (big)
			big->std = size;
		size--;
	}
}

t_stack	*ft_make_node(int value)
{
	t_stack	*node;

	node = malloc(1 * sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->std = -1;
	node->next = NULL;
	return (node);
}

t_stack	*ft_start_list(char **argv, int argc)
{
	t_stack	*stack_a;
	t_stack	*node;
	int		i;

	stack_a = NULL;
	if (argc == 2)
		i = 0;
	if (argc > 2)
		i = 1;
	while (argv[i])
	{
		if (stack_a == NULL)
			stack_a = ft_make_node(ft_atoi(argv[i]));
		else
		{
			node = stack_a;
			while (node->next)
				node = node->next;
			node->next = ft_make_node(ft_atoi(argv[i]));
		}
		i++;
	}
	return (stack_a);
}

void	ft_free_lst(t_stack **stack)
{
	t_stack	*temp;
	
	if(!*stack || !stack)
		return ;
	while(*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
	free(*stack);
}
