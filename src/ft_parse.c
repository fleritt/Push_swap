/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:11:27 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/05 11:18:06 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int ft_digit(char **argv)
{
    int i;
    int j;
    int c;

    j = 1;
    c = 0;
    while(argv[j])
    {
        i = 0;
        while(argv[j][i])
        {
            if (ft_isdigit(argv[j][i]))
                c++;
            else
            {
                if (ft_isdigit(argv[j][i + 1]) && (argv[j][i] == '-'
                    || argv[j][i] == '+'))
                    c++;
                else
                    return (-1);
            }
            i++;
        }
        j++;
    }
    return (c);
}

int ft_check_dup(int *numbers, int c)
{
    int i;
    int j;
    i = 0;
    while(i < c)
    {
        j = i + 1;
        while (j < c)
        {
            if (numbers[i] == numbers[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int *ft_args_int(char **argv, int c)
{
    int *numbers;
    int i;
    int j;
    
    numbers = malloc(sizeof(int) * c);
    j = 1;
    i = 0;
    while (argv[j])
    {
        numbers[i] = ft_atoi(argv[j]);
        j++;
        i++;
    }
    if(ft_check_dup(numbers, c))
            return (free(numbers), NULL);
    return (numbers);
}
