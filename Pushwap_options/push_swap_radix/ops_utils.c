/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvilas-p <fvilas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:45:46 by fvilas-p          #+#    #+#             */
/*   Updated: 2025/12/02 19:56:32 by fvilas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	push(t_node **dest, t_node **src)
{
	t_node	*node_to_move;

	if (!(*src))
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = *dest;
	*dest = node_to_move;
}

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*head = first->next;
	first->next = NULL;
}

void	reverse(t_node **head)
{
	t_node	*prev_last;
	t_node	*last;

	if (!(*head) || (*head)->next == NULL)
		return ;
	prev_last = NULL;
	last = *head;
	while (last->next != NULL)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *head;
	*head = last;
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		res = res * 10 + (*str - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		str++;
	}
	return ((int)(res * sign));
}
