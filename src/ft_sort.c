/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:13:46 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/28 18:14:55 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_check_sorted(t_stack *stack)
{
	t_node	*new;

	new = stack->head;
	while (new->next)
	{
		if (new->value > new->next->value)
			return (0);
		new = new->next;
	}
	return (1);
}

void	ft_sort(t_stack *a, t_stack *b, int *n, int c)
{
	if (ft_check_sorted(a))
		ft_exit(a, n, c);
	else if (c == 2)
		ft_swap(a, 'a');
	else if (c == 3)
		ft_three_sort(a);
	else if (c <= 7)
		ft_small_sort(a, b);
	else if (c > 7)
	{
		k_sort1(a, b, c);
		k_sort2(a, b, c);
	}
	else
		ft_error("");
}
