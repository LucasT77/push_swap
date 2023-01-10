/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:18 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/10 16:14:10 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *first, int *second)
{
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}

void	push(int **taken, int **given, int size_taken, int size_given)
{
	int	*taken_tmp;
	int	*given_tmp;
	int	i;

	taken_tmp = (*taken);
	given_tmp = (*given);
	(*taken) = malloc(sizeof(int) * (size_taken - 1));
	(*given) = malloc(sizeof(int) * (size_given + 1));
	(*given)[0] = taken_tmp[0];
	i = 1;
	while (i <= size_given)
	{
		(*given)[i] = given_tmp[(i - 1)];
		i++;
	}
	i = 0;
	while (i < size_taken - 1)
	{
		(*taken)[i] = taken_tmp[(i + 1)];
		i++;
	}
	free(taken_tmp);
	free(given_tmp);
}

void	rotate(int **stack, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		(*stack)[0] ^= (*stack)[i];
		(*stack)[i] ^= (*stack)[0];
		(*stack)[0] ^= (*stack)[i];
		i--;
	}
}

void	reverse_rotate(int **stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		(*stack)[size - 1] ^= (*stack)[i];
		(*stack)[i] ^= (*stack)[size - 1];
		(*stack)[size - 1] ^= (*stack)[i];
		i++;
	}
}
