/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:19:00 by marvin            #+#    #+#             */
/*   Updated: 2025/01/18 11:19:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}	t_stack;

void ft_error(char *err);
int ft_digit(char **argv);
int *ft_args_int(char **argv, int c);

#endif
