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

void	ft_push(t_stack *stack1, t_stack *stack2, char x)
{
	if (stack1->head == NULL)
		return ;
	ft_push_stack(stack2, stack1->head->value);
	stack2->head->index = stack1->head->index;
	ft_pop(stack1);
	ft_printf("p%c\n", x);
}

void	ft_swap(t_stack *stack, char x)
{
	t_node *n1;
	t_node *n2;

	n1 = stack->head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	stack->head = n2;
	ft_printf("s%c\n", x);
}

void	ft_rotate(t_stack *stack, char x)
{
	t_node	*n1;
	t_node	*n2;

	if (!stack->head || !stack->head->next)
        return;
	n1 = stack->head;
	n2 = stack->head;
	while (n2->next)
		n2 = n2->next;
	stack->head = n1->next;
	n1->next = NULL;
	n2->next = n1;
	ft_printf("r%c\n", x);
}

void	ft_reverse_rotate(t_stack *stack, char x)
{
	t_node	*n1;
	t_node	*n2;

	if (!stack->head || !stack->head->next)
        return ;
	n2 = stack->head;
	while (n2->next)
	{
		n1 = n2;
		n2 = n2->next;
	}
	n1->next = NULL;
	n2->next = stack->head;
	stack->head = n2;
	ft_printf("rr%c\n", x);
}
