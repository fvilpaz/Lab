/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:11:43 by fvilas-p          #+#    #+#             */
/*   Updated: 2026/01/13 22:29:31 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* Node structure for stack*/
typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}	t_node;

/* Swap operations*/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

/* Push operations*/
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

/* Rotate operations */
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

/* Reverse rotate operations */
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

/* utils */
t_node	*create_node(int n);
void	add_to_start(t_node **head, int n);
void	add_to_end(t_node **head, int n);
void	free_list(t_node *head);
void	free_split(char **args);
void	exit_error(t_node **stack);
void	check_duplicates(t_node *stack);
void	assign_indexes(t_node *stack);
int		is_sorted_index(t_node *stack);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

/* Internal operations */
void	swap(t_node **stack);
void	push(t_node **dest, t_node **src);
void	rotate(t_node **stack);
void	reverse(t_node **stack);

/* sort_utils*/
void	assign_args(int argc, char **argv);
void	sort_three(t_node **stack);
void	sort_small(t_node **a, t_node **b);
void	radix(t_node **a);
int		stack_size(t_node *stack);

#endif
