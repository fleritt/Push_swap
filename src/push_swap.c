/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:18:55 by marvin            #+#    #+#             */
/*   Updated: 2025/01/18 11:18:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int main (int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int     *n;
	int		c;

    if (argc < 2)
        ft_error("");
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    c = ft_digit(argv);
    if (c <= 1)
        ft_error("Error");
    n = ft_args_int(argv, c);
    if (!n)
        ft_error("Error");
    push_stack(&a, &b, c, n);
    return (0);
}
