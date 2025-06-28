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

void	ft_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		ft_pop(stack);
		i++;
	}
}

void	ft_exit(t_stack *a, int *n, int c)
{
	if (n != NULL)
		free(n);
	free_stack(a, c);
	ft_error("");
}

void	free_args(char **args, int *n)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	if (n)
		free(n);
}
