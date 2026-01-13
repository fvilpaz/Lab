/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:40:23 by fvilas-p          #+#    #+#             */
/*   Updated: 2026/01/13 21:54:09 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_node **stack)
{
	if (stack && *stack)
	{
		free_list(*stack);
		*stack = NULL;
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	check_duplicates(t_node *stack)
{
	t_node	*current_outer;
	t_node	*current_inner;

	current_outer = stack;
	while (current_outer)
	{
		current_inner = current_outer->next;
		while (current_inner)
		{
			if (current_outer->number == current_inner->number)
			{
				exit_error(&stack);
			}
			current_inner = current_inner->next;
		}
		current_outer = current_outer->next;
	}
}

void	assign_indexes(t_node *stack)
{
	t_node	*current_outer;
	t_node	*current_inner;
	int		index_count;

	current_outer = stack;
	while (current_outer)
	{
		index_count = 0;
		current_inner = stack;
		while (current_inner)
		{
			if (current_inner->number < current_outer->number)
				index_count++;
			current_inner = current_inner->next;
		}
		current_outer->index = index_count;
		current_outer = current_outer->next;
	}
}

int	is_sorted_index(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
