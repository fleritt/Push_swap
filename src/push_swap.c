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
    t_stack **a;

    a = NULL;
    if (argc < 2)
        ft_error();
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    
}