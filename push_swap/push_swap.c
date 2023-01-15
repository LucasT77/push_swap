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

void	sort_for3(char which, int **stack, int size)
{
	if (size < 3 && check(&(*stack), size) == 0)
	{
		swap(&(*stack));
		ft_printf("s%c\n", which);
	}
	if (check(&(*stack), size) == 1)
		return ;
	if ((*stack)[0] < (*stack)[1] && (*stack)[0] > (*stack)[2])
	{
		reverse_rotate(&(*stack), 3);
		ft_printf("rr%c\n", which);
		sort_for3(which, &(*stack), size);
	}
	else if ((*stack)[0] > (*stack)[1] && (*stack)[0] > (*stack)[2])
	{
		rotate(&(*stack), 3);
		ft_printf("r%c\n", which);
		sort_for3(which, &(*stack), size);
	}
	else
	{
		swap(&(*stack));
		ft_printf("s%c\n", which);
		sort_for3(which, &(*stack), size);
	}
}

void	sort_for5(int **stack_a, int **stack_b, int **sizes)
{
	int	i;

	i = sizes[0];
	while(i > 3)
	{
		selector(int &(*stack_a), &(*stack_b), &(*sizes), "pb");
		i--;
	}
	sort_for3('a', &(*stack_a), sizes[0]);
	selector(int &(*stack_a), &(*stack_b), &(*sizes), "pa");
	
	selector(int &(*stack_a), &(*stack_b), &(*sizes), "pa");
	selector(int &(*stack_a), &(*stack_b), &(*sizes), "sa");
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
	if (sizes[0] <= 3)
		sort_for3('a', &stack_a, sizes[0]);
	print_array(stack_a, sizes[0]);
	free (sizes);
	free (stack_a);
	free (stack_b);
}

/*int	litle(int **stack, int init, int end)
{
	int	smallest;

	smallest = init;
	while (init <= end)
	{
		if ((*smallest)[init] < (*stack)[smallest])
			smallest = init;
		init++;
	}
	return (smallest);
}*/
