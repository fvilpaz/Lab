/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:41:15 by fvilas-p          #+#    #+#             */
/*   Updated: 2025/12/30 21:47:25 by fvilas-p         ###   ########.fr       */
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

void assign_indexes(t_node *stack)
{
    t_node *current_outer;
    t_node *current_inner;
    int index_count;

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

int is_sorted_index(t_node *stack)
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

void	sort_two(t_node **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
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
