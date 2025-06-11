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

    if (argc == 2) 
        argv = ft_split(argv[1], ' ');
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
        argv = ft_split(aux, ' ');
        free(aux);
    }
    return (argv);
}

int main (int argc, char **argv)
{
    t_stack a;
    t_stack b;
    char    **args;
    int     *n;
	int		c;

    if (argc < 2)
        ft_error("");
    args = args_str(argc, argv);
    c = ft_digit(args);
    if (c <= 1)
        ft_error("Error");
    n = ft_args_int(args, c);
    if (!n)
        ft_error("Error");
    create_stack(&a, &b, n, c);
    free(n);
    return (0);
}
