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
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}	t_stack;

void	ft_error(char *err);
char    **args_str(int argc, char **argv);
int		ft_digit(char **argv);
int		*ft_args_int(char **argv, int c);
void	create_stack(t_stack *a, t_stack *b, int *numbers, int c);
void	ft_push_stack(t_stack *stack, int n);
long long int ft_atol(char *str);
int		ft_min_max(char **argv);
void	ft_pop(t_stack *stack);
void	ft_push(t_stack *stack1, t_stack *stack2, char x);
void    ft_swap(t_stack *stack, char x);
void	ft_rotate(t_stack *stack, char x);
void	ft_reverse_rotate(t_stack *stack, char x);
void    free_args(char **args, int *n);
void    ft_sort(t_stack *a, t_stack *b, int *n, int c);
void	ft_exit(t_stack *a, int *n, int c);
int		ft_check_sorted(t_stack *stack);
void    free_stack(t_stack *stack, int c);
void    ft_three_sort(t_stack *stack);
void	ft_small_sort(t_stack *a, t_stack *b);

#endif
