/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:13:46 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/24 06:59:17 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int ft_check_sorted(t_stack *stack)
{
    t_node *new;
    
    new = stack->head;
    while (new->next)
    {
        if (new->value > new->next->value)
            return (0);
        new = new->next;
    }
    return (1);
}

void    ft_sort(t_stack *a, int *n, int c)
{
    if (ft_check_sorted(a))
        ft_exit(a, n, c);
    else if (c == 2)
        ft_swap(a, 'a');
    else if (c == 3)
        ft_three_sort(a);
}
