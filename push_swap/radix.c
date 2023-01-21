/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:51:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/21 20:52:19 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_aux_case1(int **stack_a, int **stack_b, int **sizes, int *index)
{
	selector(&(*stack_a), &(*stack_b), &(*sizes), "sa");
	selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
	*index -= 1;
}

static void	radix_aux_case2(int **stack_a, int **stack_b, int **sizes, int *index)
{
	while (*index > 0)
	{
		selector(&(*stack_a), &(*stack_b), &(*sizes), "ra");
		*index -= 1;
	}
	selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
}

static void	radix_aux_case3(int **stack_a, int **stack_b, int **sizes, int *index)
{
	while (*index < (*sizes)[0])
	{
		selector(&(*stack_a), &(*stack_b), &(*sizes), "rra");
		*index += 1;
	}
	selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
	*index = 0;
}

static void	radix_aux(int **stack_a, int **stack_b, int **sizes, int bit)
{
	int	index;
	int	middle;

	index = 0;
	middle = (*sizes)[0] / 2;
	while (index < (*sizes)[0])
	{
		if (((*stack_a)[index] >> bit & 1) == 0 && index == 0)
			selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
		else if (((*stack_a)[index] >> bit & 1) == 0 && index == 1)
			radix_aux_case1(&(*stack_a), &(*stack_b), &(*sizes), &index);
		else if (((*stack_a)[index] >> bit & 1) == 0 && index <= middle)
			radix_aux_case2(&(*stack_a), &(*stack_b), &(*sizes), &index);
		else if (((*stack_a)[index] >> bit & 1) == 0 && index > middle)
			radix_aux_case3(&(*stack_a), &(*stack_b), &(*sizes), &index);
		else
			index++;
	}
}

void	radix(int **stack_a, int **stack_b, int **sizes)
{
	int	bit;
	int	i;

	bit = 0;
	while (bit < 32)
	{
		radix_aux(&(*stack_a), &(*stack_b), &(*sizes), bit);
		i = (*sizes)[1];
		while (i > 0)
		{
			selector(&(*stack_a), &(*stack_b), &(*sizes), "pa");
			i--;
		}
		if (check(&(*stack_a), (*sizes)[0]) == 1)
			return ;
		bit++;
	}
}
