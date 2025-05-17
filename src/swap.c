/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:50:58 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/13 18:58:45 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	ft_sa(t_stack **stack)
{
	ft_swap(stack);
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack **stack)
{
	ft_swap(stack);
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
}
