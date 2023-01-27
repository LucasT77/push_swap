/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:00:54 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/27 17:06:29 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}

int	check(int **stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if ((*stack)[i] < (*stack)[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	minor(int *stack, int size, int *index)
{
	int			i;
	static int	minor;
	static int	count;

	i = 0;
	if (count == 0)
		minor = INT_MIN;
	while (i++ < size)
	{
		if ((stack[i] > minor) || (count == 0 && stack[i] == INT_MIN))
		{
			*index = i;
			i = 0;
			while (i < size)
			{
				if (stack[i] < stack[*index] && (stack[i] > minor
						|| (count == 0 && stack[i] == INT_MIN)))
					*index = i;
				i++;
			}
		}
	}
	minor = stack[*index];
	count++;
}

int	*to_naturals(int **stack, int size)
{
	int	i;
	int	index;
	int	*newstack;

	newstack = malloc(sizeof(int) * size);
	if (!newstack)
		return (0);
	i = 0;
	while (i < size)
	{
		minor((*stack), size, &index);
		newstack[index] = i;
		i++;
	}
	free (*stack);
	return (newstack);
}
