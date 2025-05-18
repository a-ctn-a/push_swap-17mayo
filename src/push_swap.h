/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:44:25 by anzarago          #+#    #+#             */
/*   Updated: 2025/05/15 20:51:43 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				std;
	struct s_stack	*next;
}	t_stack;

void	ft_error(int argc, char **argv);
void	ft_out(int argc, char **argv);

void	ft_rev_rotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

void	ft_push(t_stack **s_from, t_stack **s_dest);
void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);

int		ft_check_double(char **argv, int argc);
int		ft_check_num(char **argv, int argc);
int		ft_check_limit(char **argv, int argc);
int		ft_checker(char **argv, int argc);
int		ft_sorted(t_stack **stack);

void	push_swap(char **argv, int argc);

t_stack	*ft_start_list(char **argv, int argc);
t_stack	*ft_make_node(int value);
void	ft_standarized(t_stack	*stack, int size);
int		ft_node_size(t_stack *stack);
void	ft_free_lst(t_stack **stack);

int		ft_find_big(t_stack *stack);
int		ft_bits(int	num);
void	ft_sort_two_three(t_stack **stack_a);
void	ft_sort_four_five(t_stack **stack_a, t_stack **stack_b);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack	**stack_a, t_stack **stack_b);

#endif