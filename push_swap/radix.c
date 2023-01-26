/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:51:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/26 16:40:53 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_aux(int **stack_a, int **stack_b, int **sizes, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = (*sizes)[0];
	while (i < size)
	{
		if (((*stack_a)[0] >> bit & 1) == 1)
			selector(&(*stack_a), &(*stack_b), &(*sizes), "ra");
		else
			selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
		i++;
	}
}

void	radix(int **stack_a, int **stack_b, int **sizes)
{
	int	bit;
	int	i;
	int	limiter;

	bit = 0;
	limiter = 0;
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
		limiter += ft_power(2, bit);
		if (limiter >= (*sizes)[0] - 1)
			break ;
		bit++;
	}
}
