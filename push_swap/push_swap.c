/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/20 16:43:11 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(int **stack_a, int **stack_b, int **sizes)
{
	int	i;
	int	index;
	int	middle;

	i = 0;
	middle = (*sizes)[0] / 2;
	while (i < 32)
	{
		index = 0;
		while (index < (*sizes)[0])
		{
			if (((*stack_a)[index] >> i & 1) == 0 && index <= middle)
			{
				while (index > 0)
				{
					selector(&(*stack_a), &(*stack_b), &(*sizes), "ra");
					index--;
				}
				selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
			}
			if (((*stack_a)[index] >> i & 1) == 0 && index == 1)
			{
				selector(&(*stack_a), &(*stack_b), &(*sizes), "sa");
				selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
				index--;
			}
			if (((*stack_a)[index] >> i & 1) == 0 && index > middle)
			{
				while (index < (*sizes)[0])
				{
					selector(&(*stack_a), &(*stack_b), &(*sizes), "rra");
					index++;
				}
				selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
				index = 0;
			}
			else
				index++;
		}
		index = 0;
		while (index < (*sizes)[1])
		{
			selector(&(*stack_a), &(*stack_b), &(*sizes), "pa");
			index++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{	
	int	*stack_a;
	int	*stack_b;
	int	boo;
	int	*sizes;

	stack_a = string_to_array(argc, argv, &boo);
	if (boo == 0)
		return (0);
	stack_b = malloc(sizeof(int) * (argc - 1));
	sizes = malloc(sizeof(int) * 2);
	if (!stack_b || !sizes)
		return (0);
	sizes[0] = argc - 1;
	sizes[1] = 0;
	if (sizes[0] <= 5)
		sort_for5(&stack_a, &stack_b, &sizes);
	else
	{
		stack_a = to_naturals(stack_a, sizes[0]);
		print_array(stack_a, sizes[0]);
		radix(&stack_a, &stack_b, &sizes);
	}
	print_array(stack_a, sizes[0]);
	free (sizes);
	free (stack_a);
	free (stack_b);
}
