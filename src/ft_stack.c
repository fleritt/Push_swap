/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:33:10 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/10 11:12:50 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_push(t_stack *stack, int n)
{
	t_node	*new;
	
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = n;
	new->next = stack->head;
	stack->head = new;
	stack->size++;
}

void	create_stack(t_stack *a, t_stack *b, int *numbers, int c)
{
	int i;

	i = c - 1;
	a->head = NULL;
	b->head = NULL;
	a->size = 0;
	b->size = 0;
	while (i >= 0)
	{
		ft_push(a, numbers[i]);
		i--;
	}
}
