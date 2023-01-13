/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/13 12:31:10 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_array(int *array, int size)
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
	int	*sizes;

	stack_a = string_to_array(argc, argv, &boo);
	if (boo == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_b = malloc(sizeof(int) * (argc - 1));
	sizes = malloc(sizeof(int) * 2);
	sizes[0] = argc - 1;
	sizes[1] = 0;
	ft_printf("1:\n");
	print_array(stack_a, sizes[0]);
	ft_printf("\n");
	ft_printf("2:\n");
	print_array(stack_b, sizes[1]);
	ft_printf("size a: %d\n", sizes[0]);
	ft_printf("size b: %d\n", sizes[1]);
	selector(&stack_a, &stack_b, &sizes, "pb");
	ft_printf("\n");
	ft_printf("3:\n");
	print_array(stack_a, sizes[0]);
	ft_printf("\n");
	ft_printf("4:\n");
	print_array(stack_b, sizes[1]);
	ft_printf("size a: %d\n", sizes[0]);
	ft_printf("size b: %d\n", sizes[1]);
	free (sizes);
	free (stack_a);
	free (stack_b);
}
