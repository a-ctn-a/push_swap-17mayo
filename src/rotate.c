/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:23:40 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/13 19:00:10 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = NULL;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
