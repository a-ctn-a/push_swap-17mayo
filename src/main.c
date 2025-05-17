/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:54:16 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/15 20:55:33 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **argv, int argc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if(!(ft_checker(argv, argc)))
		ft_error(argc, argv);	
	stack_a = ft_start_list(argv, argc);
	ft_standarized(stack_a, ft_node_size(stack_a));
	if(!(ft_sorted(&stack_a)))
		ft_out(argc,argv);
	ft_sort(&stack_a, &stack_b);
	ft_free_lst(&stack_a);
}

int	main(int argc, char **argv)
{
	char	**temp_arg;

	if (argc == 2)
	{
		temp_arg = ft_split(argv[1], ' ');
		push_swap(temp_arg, argc);
		ft_free(temp_arg);
	}
	if (argc > 2)
		push_swap(argv, argc);
	if (argc < 2)
		exit (0);
	return (0);
}
