/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:46:18 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/28 18:24:35 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_three_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

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

int	ft_min_pos(t_stack *stack)
{
	t_node	*tmp;
	int		i;
	int		min;
	int		min_pos;

	tmp = stack->head;
	min = tmp->value;
	i = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	ft_push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = ft_min_pos(a);
	while (pos > 0 && pos < a->size)
	{
		if (pos <= a->size / 2)
			ft_rotate(a, 'a');
		else
			ft_reverse_rotate(a, 'a');
		pos = ft_min_pos(a);
	}
	ft_push(a, b, 'b');
}

void	ft_small_sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		ft_push_min_to_b(a, b);
	ft_three_sort(a);
	while (b->size > 0)
		ft_push(b, a, 'a');
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}
