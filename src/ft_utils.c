/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:44:33 by marvin            #+#    #+#             */
/*   Updated: 2025/01/21 12:44:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void    ft_swap(t_stack *stack, char x_stack)
{
    t_node *n1;
    t_node *n2;

    n1 = stack->head;
    n2 = n1->next;
    n1->next = n2->next;
    n2->next = n1;
    stack->head = n2;
    ft_printf("s%c\n", x_stack);
}