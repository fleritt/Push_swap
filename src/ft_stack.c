/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:33:10 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/28 11:54:43 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_push_stack(t_stack *stack, int n)
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

void	ft_pop(t_stack *stack)
{
	t_node	*pop;
	
	if (!stack->head)
		return ;
	pop = stack->head;
	stack->head = pop->next;
	free(pop);
	pop = NULL;
	stack->size--;
}

int	index_of(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}

void	insertion_sort(int *array, int n)
{
	int	element;
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
		i++;
	}
}

void	create_stack(t_stack *a, t_stack *b, int *numbers, int c)
{
	int i;
	t_node *temp;
	
	i = c - 1;
	a->head = NULL;
	b->head = NULL;
	a->size = 0;
	b->size = 0;
	while (i >= 0)
	{
		ft_push_stack(a, numbers[i]);
		i--;
	}
	insertion_sort(numbers, c);
	temp = a->head;
	while (temp)
	{
		temp->index = index_of(temp->value, numbers);
		temp = temp->next;
	}
}
