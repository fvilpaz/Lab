/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:41:15 by fvilas-p          #+#    #+#             */
/*   Updated: 2026/01/01 04:50:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>  // para NULL, exit

static int  is_num(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    t_node  *a = NULL;
    t_node  *b = NULL;
    char    **args;
    int     i;

    if (argc < 2)
        return 0;

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
            exit_error(&a, &b);
        }
        add_to_end(&a, ft_atoi(args[i++]));
    }

    if (argc == 2)
        free_split(args);

    check_duplicates(a);
    assign_indexes(a);

    if (!is_sorted_index(a))
    {
        int size = stack_size(a);

        if (size == 2)
            sort_two(&a);
        else if (size == 3)
            sort_three(&a);
        else if (size <= 5)
            sort_small(&a, &b);
        else
            turk_sort(&a);
    }

    // Liberar memoria al final
    free_list(a);
    if (b)
        free_list(b);

    return 0;
}
