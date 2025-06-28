/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:05:01 by rfleritt          #+#    #+#             */
/*   Updated: 2025/06/27 22:09:15 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int *s, int length)
{
	int	    *number;
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (NULL);
	}
	number = malloc(sizeof(int) * length);
	if (number == NULL)
	{
		return (NULL);
	}
	while (i < length)
	{
		number[i] = s[i];
		i++;
	}
	return (number);
}