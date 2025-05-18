/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:48:37 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/13 19:01:36 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	temp1 = *stack;
	while (temp1->next)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	temp1->next = *stack;
	temp2 ->next = NULL;
	*stack = temp1;
}

void	ft_rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
