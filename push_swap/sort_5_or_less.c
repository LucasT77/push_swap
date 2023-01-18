/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_or_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:59:25 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/18 16:59:26 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	little(int **stack, int init, int end)
{
	int	smallest;

	smallest = init;
	while (init <= end)
	{
		if ((*stack)[init] < (*stack)[smallest])
			smallest = init;
		init++;
	}
	return (smallest);
}

void	minor_to_top(int which, int **stack, int size)
{
	int	minor;
	int	end;

	end = size - 1;
	minor = little(&(*stack), 0, end);
	if (minor - 0 <= end - minor)
	{
		while (minor > 0)
		{
			rotate(&(*stack), size);
			ft_printf("r%c\n", which);
			minor--;
		}	
	}
	else if (minor - 0 > end - minor)
	{
		while (minor != end + 1)
		{
			reverse_rotate(&(*stack), size);
			ft_printf("rr%c\n", which);
			minor++;
		}	
	}
}

void	sort_for5(int **stack_a, int **stack_b, int **sizes)
{
	int	i;
	int	cont;

	i = (*sizes)[0];
	cont = 0;
	if (check(&(*stack_a), (*sizes)[0]) == 1)
		return ;
	while (i > 3)
	{
		minor_to_top('a', &(*stack_a), (*sizes)[0]);
		selector(&(*stack_a), &(*stack_b), &(*sizes), "pb");
		cont++;
		i--;
	}
	sort_for3('a', &(*stack_a), i);
	while (cont > 0)
	{
		selector(&(*stack_a), &(*stack_b), &(*sizes), "pa");
		cont--;
	}
}
