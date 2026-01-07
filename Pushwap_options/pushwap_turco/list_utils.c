/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:17:33 by fvilas-p          #+#    #+#             */
/*   Updated: 2025/12/30 17:47:53 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int n)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->number = n;
	result->index = 0;
	result->next = NULL;
	return (result);
}

void	add_to_start(t_node **head, int n)
{
	t_node	*new_node;

	new_node = create_node(n);
	if (!new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

void	add_to_end(t_node **head, int n)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(n);
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*tmp;

	current = head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}
