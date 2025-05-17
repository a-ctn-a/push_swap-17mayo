/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:24:15 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/13 19:02:29 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **s_from, t_stack **s_dest)
{
	t_stack	*temp;

	if ((*s_from == NULL) || (s_from == NULL))
		return ;
	temp = *s_from;
	*s_from = (*s_from)->next;
	if (*s_dest)
	{
		temp->next = *s_dest;
		*s_dest = temp;
	}
	else
	{
		temp->next = NULL;
		*s_dest = temp;
	}
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
