/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:41:15 by fvilas-p          #+#    #+#             */
/*   Updated: 2026/01/01 05:04:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exit_error(t_node **a, t_node **b)
{
    if (a && *a)
    {
        free_list(*a);
        *a = NULL;
    }
    if (b && *b)
    {
        free_list(*b);
        *b = NULL;
    }
    write(2, "Error\n", 6);
    exit(1);
}

void check_duplicates(t_node *stack)
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
				exit_error(&stack, NULL); // correcto para tu exit_error
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

void sort_two(t_node **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

void sort_three(t_node **stack)
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

int	get_min_index(t_node *stack)
{
	int	min_index;

	if (!stack)
		return (-1); // O manejar el error según tu norma

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

int	get_max_index(t_node *stack)
{
	int	max_index;

	if (!stack)
		return (-1);

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	get_pos_of_index(t_node *stack, int index)
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
int	get_target_position_in_b(t_node *b, int index_to_push)
{
	int		target_pos;
	int		min_index;
	int		max_index;
	t_node	*current;

	target_pos = 0;
	current = b;
	min_index = get_min_index(b);
	max_index = get_max_index(b);
	if (index_to_push < min_index || index_to_push > max_index)
	{
		target_pos = get_pos_of_index(b, max_index);
	}
	else
	{
		while (current)
		{
			if (current->index < index_to_push && current->next->index > index_to_push)
				return (target_pos + 1);
			current = current->next;
			target_pos++;
		}
	}
	return (target_pos);
}
int	get_target_position_in_a(t_node *a, int index_to_push)
{
	int		target_pos;
	int		min_index;
	int		max_index;
	t_node	*current;

	target_pos = 0;
	current = a;
	min_index = get_min_index(a);
	max_index = get_max_index(a);
	
	if (index_to_push > max_index || index_to_push < min_index)
	{
		target_pos = get_pos_of_index(a, min_index);
	}
	else
	{
		while (current)
		{
			if (current->index < index_to_push && current->next->index > index_to_push)
				return (target_pos + 1);
			current = current->next;
			target_pos++;
		}
	}
	return (target_pos);
}
void	calculate_rotation_cost(int pos, int size, int *ra_cost, int *rra_cost)
{
	if (pos <= size / 2)
	{
		*ra_cost = pos;
		*rra_cost = 0;
	}
	else
	{
		*ra_cost = 0;
		*rra_cost = size - pos;
	}
}

int	calculate_total_cost(t_costs costs)
{
	if (costs.ra && costs.rb)
		return (costs.rr + costs.ra + costs.rb);
	if (costs.rra && costs.rrb)
		return (costs.rrr + costs.rra + costs.rrb);
	return (costs.ra + costs.rra + costs.rb + costs.rrb);
}

int	calculate_cheapest_move(t_node *a, t_node *b)
{
	t_node	*current_b;
	int		cheapest_index;
	int		min_cost;
	t_costs	costs;

	current_b = b;
	min_cost = 2147483647;
	cheapest_index = -1;
	while (current_b)
	{
		int pos_a = get_target_position_in_a(a, current_b->index);
		int pos_b = get_pos_of_index(b, current_b->index);

		calculate_rotation_cost(pos_a, stack_size(a), &costs.ra, &costs.rra);
		calculate_rotation_cost(pos_b, stack_size(b), &costs.rb, &costs.rrb);

		costs.rr = (costs.ra < costs.rb) ? costs.ra : costs.rb;
		costs.rrr = (costs.rra < costs.rrb) ? costs.rra : costs.rrb;
		costs.total = calculate_total_cost(costs);
		
		if (costs.total < min_cost)
		{
			min_cost = costs.total;
			cheapest_index = current_b->index;
		}
		current_b = current_b->next;
	}
	return (cheapest_index);
}
void	apply_combined_rotations(t_node **a, t_node **b, t_costs costs)
{
	while (costs.rr-- > 0)
		rr(a, b);
	while (costs.rrr-- > 0)
		rrr(a, b);
}

void	apply_individual_rotations(t_node **a, t_node **b, t_costs costs)
{
	while (costs.ra-- > 0)
		ra(a);
	while (costs.rb-- > 0)
		rb(b);
	while (costs.rra-- > 0)
		rra(a);
	while (costs.rrb-- > 0)
		rrb(b);
}

void	execute_cheapest_move(t_node **a, t_node **b, int cheapest_index)
{
	t_costs	costs;
	int		pos_a;
	int		pos_b;

	pos_b = get_pos_of_index(*b, cheapest_index);
	pos_a = get_target_position_in_a(*a, cheapest_index);

	calculate_rotation_cost(pos_a, stack_size(*a), &costs.ra, &costs.rra);
	calculate_rotation_cost(pos_b, stack_size(*b), &costs.rb, &costs.rrb);

	costs.rr = (costs.ra < costs.rb) ? costs.ra : costs.rb;
	costs.rrr = (costs.rra < costs.rrb) ? costs.rra : costs.rrb;

	apply_combined_rotations(a, b, costs);
	apply_individual_rotations(a, b, costs);

	pa(a, b);
}
void	turk_sort(t_node **a)
{
	t_node	*b;
	int		cheapest_index;
	b = NULL;

	while (stack_size(*a) > 3)
		pb(a, &b);
	
	sort_three(a);
	
	while (b)
	{
		cheapest_index = calculate_cheapest_move(*a, b);
		execute_cheapest_move(a, &b, cheapest_index);
	}

	while (get_min_pos(*a) != 0)
	{
		if (get_min_pos(*a) <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}
