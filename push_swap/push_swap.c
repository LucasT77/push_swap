/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/12 18:20:22 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_array(int *array, int size)
{
    int i;

    i = 0;
    while (i < size)
        ft_printf("%d\n", array[i++]);
}

int	main(int argc, char **argv)
{	
	int	*stack_a;
	int	*stack_b;
	int	boo;
	int	*sizes[2];

	stack_a = string_to_array(argc, argv, &boo);
	if (boo == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_b = malloc(sizeof(int) * (argc - 1));
	sizes[0] = argc - 1;
	sizes[1] = 0;
	print_array(stack_a, sizes[0]);
	ft_printf("\n");
	print_array(stack_b, sizes[1]);
	operations(&stack_a, &stack_b, &(*sizes), "pb");
	ft_printf("\n");
	print_array(stack_a, sizes[0]);
	ft_printf("\n");
	print_array(stack_b, sizes[1]);
	free (stack_a);
	free (stack_b);
}
