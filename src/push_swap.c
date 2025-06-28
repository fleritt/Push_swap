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

static char	*ft_free_strjoin(char *r, char *buffer)
{
	char	*aux;
	int		i;

	aux = ft_strjoin(r, buffer);
	if (!aux)
		return (free(r), NULL);
	i = 0;
	if (aux[i] == '\0')
	{
		free(aux);
		return (free(r), NULL);
	}
	return (free(r), aux);
}

char    **args_str(int argc, char **argv)
{
    int j;
    char *aux;
    char **args;

    if (argc == 2) 
        args = ft_split(argv[1], ' ');
    else
    {
        j = 1;
        aux = ft_strdup(argv[j]);
        if (!aux)
            ft_error("error malloc");
        while (++j < argc)
        {
            aux = ft_free_strjoin(aux, " ");
            aux = ft_free_strjoin(aux, argv[j]);
        }
        args = ft_split(aux, ' ');
        free(aux);
    }
    return (args);
}

int main (int argc, char **argv)
{
    t_stack a;
    t_stack b;
    char    **args;
    int     *n;
	int		c;
    int     *sort;

    if (argc < 2)
        ft_error("");
    args = args_str(argc, argv);
    c = ft_digit(args);
    n = ft_args_int(args, c);
    if (!n || c <= 1)
    {
        free_args(args, n);
        ft_error("Error\n");
    }
    sort = ft_intdup(n, c);
    create_stack(&a, &b, sort, c);
    ft_sort(&a, &b, n, c);
    free(sort);
    free_args(args, n);
    free_stack(&a, c);
    return (0);
}
