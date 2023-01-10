/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/10 16:33:54 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	int	*stack_a;
	int	*stack_b;
	int	boo;

	stack_a = string_to_array(argc, argv, &boo);
	stack_b = malloc(sizeof(int) * (argc - 1));
	if (boo == 0)
	{
		printf("Error\n");
		return (0);
	}
	/*while (i < argc - 1)
	{
		printf("%d\n", stack[i]);
		i++;
	}*/
	free (stack_a);
	free (stack_b);
}
