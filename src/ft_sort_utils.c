/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:46:18 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/24 08:51:56 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void    ft_three_sort(t_stack *stack)
{
	int	a;
	int b;
	int c;

	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->next->next->value;

	if (a < b && b > c && a < c)
	{
		ft_reverse_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		ft_rotate(stack, 'a');
	else if (a < b && b > c && a > c)
		ft_reverse_rotate(stack, 'a');
	else if (a > b && b < c && a < c)
		ft_swap(stack, 'a');
	else if (a > b && b > c && a > c)
	{
		ft_rotate(stack, 'a');
		ft_swap(stack, 'a');
	}
}
