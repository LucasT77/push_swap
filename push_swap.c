/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:20 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		while (j < ft_strlen(argv[i]))
		{
			if (j == 0 && argv[i][j] == '-')
			{
				j++;
				continue ;
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	*string_to_array(int argc, char **argv, int *boo)
{
	int	*stack;
	int	i;
	int	cont;	

	*boo = 1;
	if (error_checker(argc, argv) == 0)
		*boo = 0;
	stack = malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		if (char_to_int(argv[i], &stack[(i-1)]) == 0)
			*boo = 0;
		cont = 0;
		while (cont < (i-1))
		{
			if (stack[(i-1)] == stack[cont])
				*boo = 0;
			cont++;
		}
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{	
	int	i;
	int	*stack;
	int	boo;

	stack = string_to_array(argc, argv, &boo);
	if (boo == 0)
	{
		printf("Error\n");
		return (0);
	}
	while (i < argc - 1)
	{
		printf("%d\n", stack[i]);
		i++;
	}
}
