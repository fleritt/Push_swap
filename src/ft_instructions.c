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

void	ft_swap(t_stack *stack)
{
	t_node *n1;
	t_node *n2;

	n1 = stack->head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stack->head = n2;
}

void	ft_rotate(t_stack *stack)
{
	t_node	*n1;
	t_node	*n2;

	n1 = stack->head;
	while (n1)
	{
		if (n1->next == NULL)
			n2 = n1;
		n1 = n1->next; 
	}
	n2 = n2->next;
	n2 = stack->head;
	n2->next = NULL;
	stack->head = stack->head->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*n1;
	t_node	*n2;
	int		i;

	i = 0;
	n1 = stack->head;
	while (i < stack->size - 1)
		n1 = n1->next;
	n2 = n1->next;
	n1->next = NULL;
	n2->next = stack->head;
	stack->head = n2;
}