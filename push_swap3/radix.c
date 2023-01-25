/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:51:29 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/25 18:19:11 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    to_binary(int num)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int));
    i = 0;
    while (num > 0)
    {
        if (num % 2 > 0)
            arr[i] = 1;
        else
            arr[i] = 0;
        i++;
        num /= 2;
    }
    while (i > 0)
    {
        ft_printf("%d", arr[i - 1]);
        i--;
    }
}

void	print_array_binary(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		to_binary(array[i]);
		ft_printf("\n");
		i++;
	}
}

/*static void	radix_aux1(int **stack_a, int **stack_b, int **sizes, int *index)
{
	selector(&(*stack_a), &(*stack_b), &(*sizes), "sa");
	selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
	*index -= 1;
}

static void	radix_aux2(int **stack_a, int **stack_b, int **sizes, int *index)
{
	while (*index > 0)
	{
		selector(&(*stack_a), &(*stack_b), &(*sizes), "ra");
		*index -= 1;
	}
	selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
}

static void	radix_aux3(int **stack_a, int **stack_b, int **sizes, int *index)
{
	while (*index < (*sizes)[0])
	{
		selector(&(*stack_a), &(*stack_b), &(*sizes), "rra");
		*index += 1;
	}
	selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
	*index = 0;
}*/

static void	radix_aux(int **stack_a, int **stack_b, int **sizes, int bit)
{
	int	index;
	int	middle;

	index = 0;
	middle = (*sizes)[0] / 2;
	while (index < (*sizes)[0])
	{
		/*if (((*stack_a)[index] >> bit & 1) == 0 && index == 0)
			selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
		else if (((*stack_a)[index] >> bit & 1) == 0 && index == 1)
			radix_aux1(&(*stack_a), &(*stack_b), &(*sizes), &index);
		else if (((*stack_a)[index] >> bit & 1) == 0 && index <= middle)
			radix_aux2(&(*stack_a), &(*stack_b), &(*sizes), &index);
		else if (((*stack_a)[index] >> bit & 1) == 0 && index > middle)
			radix_aux3(&(*stack_a), &(*stack_b), &(*sizes), &index);
		else
			index++;*/
		if (((*stack_a)[index] >> bit & 1) == 0)
		{
			selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
			index = 0;
		}
		else
		{
			selector(&(*stack_a), &(*stack_b), &(*sizes), "ra");
			index++;
		}
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
		ft_printf("stack_a:\n");
		print_array_binary((*stack_a), (*sizes)[0]);
		ft_printf("\nstack_b:\n");
		print_array_binary((*stack_b), (*sizes)[1]);
		//if ((*sizes)[0] <= 5)
		//	sort_for5(&(*stack_a), &(*stack_b), &(*sizes));
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
