/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:18 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/09 16:26:43 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sa(int *stack_a)
{
	stack_a[0] ^= stack_a[1];
	stack_a[1] ^= stack_a[0];
	stack_a[0] ^= stack_a[1];
	return (stack_a);
}

int	*sb(int *stack_b)
{
	stack_b[0] ^= stack_b[1];
	stack_b[1] ^= stack_b[0];
	stack_b[0] ^= stack_b[1];
	return (stack_b);
}

int	*ss(int *stack_a, int *stack_b)
{
	stack_a = sa(stack_a);
	stack_b = sb(stack_b);
}
