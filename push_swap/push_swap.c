/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/26 17:44:25 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	int	*stack_a;
	int	*stack_b;
	int	*sizes;

	if (organizer(argc, argv, &stack_a, &sizes) == 0)
		return (0);
	stack_b = malloc(sizeof(int) * (argc - 1));
	if (!stack_b)
		return (0);
	if (sizes[0] <= 5)
		sort_for5(&stack_a, &stack_b, &sizes);
	else
	{
		stack_a = to_naturals(&stack_a, sizes[0]);
		radix(&stack_a, &stack_b, &sizes);
	}
	print_array(stack_a, sizes[0]);
	free (sizes);
	free (stack_a);
	free (stack_b);
}

// Problema ao usar INT_MIN