/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/15 19:49:03 by luaraujo         ###   ########.fr       */
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
	sizes[0] = argc - 1;
	sizes[1] = 0;
	if (sizes[0] <= 5)
		sort_for5(&stack_a, &stack_b, &sizes);
	print_array(stack_a, sizes[0]);
	free (sizes);
	free (stack_a);
	free (stack_b);
}
