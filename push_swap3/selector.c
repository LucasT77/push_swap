/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:23:15 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/15 17:33:54 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selector_sp(int **stack_a, int **stack_b, int **sizes, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(&(*stack_a));
	if (ft_strncmp(op, "sb", 2) == 0)
		swap(&(*stack_b));
	if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(&(*stack_a));
		swap(&(*stack_b));
	}
	if (ft_strncmp(op, "pa", 2) == 0)
	{
		push(&(*stack_b), &(*stack_a), (*sizes)[1], (*sizes)[0]);
		(*sizes)[1] -= 1;
		(*sizes)[0] += 1;
	}
	if (ft_strncmp(op, "pb", 2) == 0)
	{
		push(&(*stack_a), &(*stack_b), (*sizes)[0], (*sizes)[1]);
		(*sizes)[0] -= 1;
		(*sizes)[1] += 1;
	}
}

static void	selector_r(int **stack_a, int **stack_b, int **sizes, char *op)
{
	if (ft_strncmp(op, "ra", 2) == 0)
		rotate(&(*stack_a), (*sizes)[0]);
	if (ft_strncmp(op, "rb", 2) == 0)
		rotate(&(*stack_b), (*sizes)[1]);
	if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(&(*stack_a), (*sizes)[0]);
		rotate(&(*stack_b), (*sizes)[1]);
	}
	if (ft_strncmp(op, "rra", 2) == 0)
		reverse_rotate(&(*stack_a), (*sizes)[0]);
	if (ft_strncmp(op, "rrb", 2) == 0)
		reverse_rotate(&(*stack_b), (*sizes)[1]);
	if (ft_strncmp(op, "rrr", 2) == 0)
	{
		reverse_rotate(&(*stack_a), (*sizes)[0]);
		reverse_rotate(&(*stack_b), (*sizes)[1]);
	}
}

void	selector(int **stack_a, int **stack_b, int **sizes, char *op)
{
	if (op[0] == 's' || op[0] == 'p')
		selector_sp(&(*stack_a), &(*stack_b), &(*sizes), op);
	if (op[0] == 'r')
		selector_r(&(*stack_a), &(*stack_b), &(*sizes), op);
	ft_printf("%s\n", op);
}
