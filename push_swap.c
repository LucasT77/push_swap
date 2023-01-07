/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:01 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/07 21:15:12 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

struct push_swap
{
	int	value;
	struct push_swap *next;
};
typedef struct push_swap list_t;

list_t	*ft_lstnew(int content)
{
	list_t	*result;

	result = malloc(sizeof(list_t));
	if (!result)
		return (0);
	result->value = content;
	result->next = NULL;
	return (result);
}

int	char_to_int(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
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
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	printlist(list_t *head)
{
	list_t	*aux;

	aux = head;
	while (aux != NULL)
	{
		printf("%d - ", aux->value);
		aux = aux->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{	
	int		i;
	list_t	*head;
	int		n;

	if (error_checker(argc, argv) == 0)
	{
		write(1, "Error", 5);
		return (0);
	}
	n.value = char_to_int(argv[1]);
	head = &n;
	i = 2;
	while (argv[i])
		ft_lstnew(char_to_int(argv[i]));
	printlist(head);

}
