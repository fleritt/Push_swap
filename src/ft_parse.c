/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:11:27 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/27 22:55:32 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int ft_digit(char **argv)
{
    int i;
    int j;
    int c;

    j = 0;
    c = 0;
    while(argv[j])
    {
        i = 0;
        while(argv[j][i])
        {
            if ((argv[j][i] == '-' || argv[j][i] == '+') && ft_isdigit(argv[j][i + 1]))
                i++;
            if (ft_isdigit(argv[j][i]))
            {
                c++;
                while (ft_isdigit(argv[j][i]))
                    i++;
            }
            else
				return (-1);
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

long long int ft_atol(char *str)
{
	size_t			i;
	size_t			n;
	long long int	num;

	i = 0;
	n = 1;
	num = 0;
	while (str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * n);
}

int ft_min_max(char **argv)
{
	int	i;

	i = 0;
    while(argv[i])
    {
        if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
            return (1);
        i++;
    }
    return (0);
}

int *ft_args_int(char **argv, int c)
{
    int *numbers;
    int i;
    int j;
    
	if (ft_min_max(argv))
		return (NULL);
    numbers = malloc(sizeof(int) * c);
    if (!numbers)
        return (NULL);
    j = 0;
    i = 0;
    while (argv[j])
    {
        numbers[i] = ft_atoi(argv[j]);
        j++;
        i++;
    }
    if (ft_check_dup(numbers, c))
            return (free(numbers), NULL);
    return (numbers);
}
