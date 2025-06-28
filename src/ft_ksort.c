/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:14:00 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/28 18:17:43 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (result <= n)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

static int	rotation_count_tohead(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->index == index)
			return (counter);
		stack = stack->next;
		counter++;
	}
	return (-1);
}

void	k_sort1(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(size) * 14 / 10;
	while (a->head != NULL)
	{
		if (a->head->index <= i)
		{
			ft_push(a, b, 'b');
			i++;
		}
		else if (a->head->index <= i + range)
		{
			ft_push(a, b, 'b');
			ft_rotate(b, 'b');
			i++;
		}
		else
			ft_rotate(a, 'a');
	}
}

void	k_sort2(t_stack *a, t_stack *b, int size)
{
	int	rb_count;
	int	rrb_count;

	while (size - 1 >= 0)
	{
		rb_count = rotation_count_tohead(b->head, size - 1);
		rrb_count = b->size - rb_count;
		if (rb_count <= rrb_count)
		{
			while (b->head->index != size - 1)
				ft_rotate(b, 'b');
			ft_push(b, a, 'a');
			size--;
		}
		else
		{
			while (b->head->index != size - 1)
				ft_reverse_rotate(b, 'b');
			ft_push(b, a, 'a');
			size--;
		}
	}
}
