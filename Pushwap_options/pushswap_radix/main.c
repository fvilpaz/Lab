/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:52:58 by fvilas-p          #+#    #+#             */
/*   Updated: 2025/12/30 21:28:48 by fvilas-p         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**args;
	int		i;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		if (!is_num(args[i]))
		{
			if (argc == 2)
				free_split(args);
			exit_error(&a);
		}
		add_to_end(&a, ft_atoi(args[i++]));
	}
	if (argc == 2)
		free_split(args);
	check_duplicates(a);
	assign_indexes(a);
	if (!is_sorted_index(a))
	{
		if (stack_size(a) == 2)
			sort_two(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else if (stack_size(a) <= 5)
			sort_small(&a, &b);
		else
			radix(&a);
	}
	free_list(a);
	return (0);
}
