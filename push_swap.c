/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/08 20:06:53 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

int	char_to_int(char *str, int *num)
{
	int	n;
	int	i;
	int	signal;

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
		if ((n * 10) + (str[i] - '0') > INT_MAX)
			return (0);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	n *= signal;
	*num = n;
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

//int	string_to_array()

int	main(int argc, char **argv)
{	
	int	i;
	int	*nums;

	if (error_checker(argc, argv) == 0)
	{
		printf("Error\n");
		return (0);
	}
	nums = malloc(sizeof(int) * argc);
	i = 1;
	while (i < argc)
	{
		if (char_to_int(argv[i], &nums[(i-1)]) == 0)
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	nums[(i-1)] = '!';
	i = 0;
	while (nums[i] != '!')
	{
		printf("%d\n", nums[i]);
		i++;
	}
}
