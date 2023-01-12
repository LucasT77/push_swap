/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:18 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/12 18:07:43 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	operations(int **stackA, int **stackB, int **sizeAB, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(&(*stackA)[0], &(*stackA)[1]);
	if (ft_strncmp(op, "sb", 2) == 0)
		swap(&(*stackB)[0], &(*stackB)[1]);
	if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(&(*stackA)[0], &(*stackA)[1]);
		swap(&(*stackB)[0], &(*stackB)[1]);
	}
	if (ft_strncmp(op, "pa", 2) == 0)
	{
		push(&(*stackB), &(*stackA), *sizeB, *sizeA);
		*sizeAB[1] -= 1;
		*sizeAB[0] += 1;
	}
	if (ft_strncmp(op, "pb", 2) == 0)
	{
		push(&(*stackA), &(*stackB), *sizeA, *sizeB);
		*sizeAB[0] -= 1;
		*sizeAB[1] += 1;
	}
	if (ft_strncmp(op, "ra", 2) == 0)
		rotate(&(*stackA), *sizeA);
	if (ft_strncmp(op, "rb", 2) == 0)
		rotate(&(*stackB), *sizeB);
	if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(&(*stackA), *sizeA);
		rotate(&(*stackB), *sizeB);
	}
	if (ft_strncmp(op, "rra", 2) == 0)
		reverse_rotate(&(*stackA), *sizeA);
	if (ft_strncmp(op, "rrb", 2) == 0)
		reverse_rotate(&(*stackB), *sizeB);
	if (ft_strncmp(op, "rrr", 2) == 0)
	{
		reverse_rotate(&(*stackA), *sizeA);
		reverse_rotate(&(*stackB), *sizeB);
	}
}*/

void	swap(int *first, int *second)
{
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}

void	push(int **taken, int **given, int size_taken, int size_given)
{
	int	*taken_tmp;
	int	*given_tmp;
	int	i;

	taken_tmp = (*taken);
	given_tmp = (*given);
	(*taken) = malloc(sizeof(int) * (size_taken - 1));
	(*given) = malloc(sizeof(int) * (size_given + 1));
	(*given)[0] = taken_tmp[0];
	i = 1;
	while (i <= size_given)
	{
		(*given)[i] = given_tmp[(i - 1)];
		i++;
	}
	i = 0;
	while (i < size_taken - 1)
	{
		(*taken)[i] = taken_tmp[(i + 1)];
		i++;
	}
	free(taken_tmp);
	free(given_tmp);
}

void	rotate(int **stack, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		(*stack)[0] ^= (*stack)[i];
		(*stack)[i] ^= (*stack)[0];
		(*stack)[0] ^= (*stack)[i];
		i--;
	}
}

void	reverse_rotate(int **stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		(*stack)[size - 1] ^= (*stack)[i];
		(*stack)[i] ^= (*stack)[size - 1];
		(*stack)[size - 1] ^= (*stack)[i];
		i++;
	}
}
