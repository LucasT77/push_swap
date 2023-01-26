/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:46 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/23 18:16:57 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	organizer(int argc, char **argv, int **stack_a, int **sizes)
{
	char	**str;
	int		length;

	if (error_checker(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	str = ft_split(argv[1], ' ');
	length = 0;
	while (str[length])
		length++;
	if (string_to_array(length, str, &(*stack_a)) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	*sizes = malloc(sizeof(int) * 2);
	if (!(*sizes))
		return (0);
	(*sizes)[0] = length;
	(*sizes)[1] = 0;
	return (1);
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%d\n", array[i++]);
}

int	char_to_int(char *str, int *num)
{
	long int	n;
	int			i;
	int			signal;

	i = 0;
	n = 0;
	signal = 1;
	if (str[i] == '-')
	{
		signal *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (signal == 1 && (n * 10) + (str[i] - '0') > INT_MAX)
			return (0);
		if (signal == -1 && (n * 10) + (str[i] - '0') > 2147483648)
			return (0);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	n *= signal;
	*num = (int)n;
	return (1);
}

int	error_checker(int argc, char **argv)
{
	int	j;

	j = 0;
	if (argc != 2)
		return (0);
	while (j < (int)ft_strlen(argv[1]))
	{
		if (argv[1][j] == '-')
		{
			if ((j != 0 && argv[1][j - 1] != ' ')
				|| ft_isdigit(argv[1][j + 1]) == 0)
				return (0);
			j++;
			continue ;
		}
		if (ft_isdigit(argv[1][j]) == 0 && argv[1][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	string_to_array(int length, char **str, int **stack_a)
{
	int	i;
	int	cont;	

	*stack_a = malloc(sizeof(int) * length);
	if (!(*stack_a))
		return (0);
	i = 0;
	while (i < length)
	{
		if (char_to_int(str[i], &(*stack_a)[i]) == 0)
			return (0);
		cont = 0;
		while (cont < i)
		{
			if ((*stack_a)[i] == (*stack_a)[cont])
			{
				return (0);
			}
			cont++;
		}
		i++;
	}
	return (1);
}
