/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/28 17:18:55 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_me_on_my_way(int **stack_a, int **stack_b, int **sizes)
{
	if ((*sizes)[0] <= 5)
		sort_for5(&(*stack_a), &(*stack_b), &(*sizes));
	else
	{
		(*stack_a) = to_naturals(&(*stack_a), (*sizes)[0]);
		radix(&(*stack_a), &(*stack_b), &(*sizes));
	}
}

int	main(int argc, char **argv)
{	
	int	*stack_a;
	int	*stack_b;
	int	*sizes;

	if (argc != 2)
		return (0);
	if (organizer(argc, argv, &stack_a, &sizes) == 0)
	{
		free (sizes);
		free (stack_a);
		ft_printf("Error\n");
		return (0);
	}
	stack_b = malloc(sizeof(int) * (argc - 1));
	if (!stack_b)
		return (0);
	send_me_on_my_way(&stack_a, &stack_b, &sizes);
	free (sizes);
	free (stack_a);
	free (stack_b);
}
