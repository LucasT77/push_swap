/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:00:54 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/21 18:09:55 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	minor(int *stack, int size)
{
	int			i;
	int			index;
	static int	minor;
	static int	count;

	i = 0;
	if (count == 0)
		minor = INT_MIN;
	while (i++ < size)
	{
		if (stack[i] > minor)
		{
			index = i;
			i = 0;
			while (i < size)
			{
				if (stack[i] < stack[index] && stack[i] > minor)
					index = i;
				i++;
			}
		}
	}
	minor = stack[index];
	count++;
	return (index);
}

int	*to_naturals(int *stack, int size)
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
		index = minor(stack, size);
		newstack[index] = i;
		i++;
	}
	return (newstack);
}
