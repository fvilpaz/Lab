/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:41:15 by fvilas-p          #+#    #+#             */
/*   Updated: 2026/01/13 22:38:02 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_position(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	get_min_pos(t_node *stack)
{
	int	pos;
	int	min_pos;
	int	min_index;

	pos = 0;
	min_pos = 0;
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		if (get_min_pos(*a) <= size / 2)
		{
			while (get_min_pos(*a) != 0)
				ra(a);
		}
		else
		{
			while (get_min_pos(*a) != 0)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	radix(t_node **a)
{
	t_node	*b;
	int		size;
	int		max_bits;
	int		i;
	int		j;

	b = NULL;
	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((*a)->index >> i & 1) == 0)
				pb(a, &b);
			else
				ra(a);
		}
		while (b)
			pa(a, &b);
	}
}
