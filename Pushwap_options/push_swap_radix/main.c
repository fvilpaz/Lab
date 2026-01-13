/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:52:58 by fvilas-p          #+#    #+#             */
/*   Updated: 2026/01/13 22:50:34 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	load_args(t_node **a, char **args, int argc)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_num(args[i]))
		{
			if (argc == 2)
				free_split(args);
			exit_error(a);
		}
		add_to_end(a, ft_atoi(args[i++]));
	}
}

static void	select_algorithm(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		radix(a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**args;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	load_args(&a, args, argc);
	if (argc == 2)
		free_split(args);
	check_duplicates(a);
	assign_indexes(a);
	if (!is_sorted_index(a))
		select_algorithm(&a, &b);
	free_list(a);
	return (0);
}
