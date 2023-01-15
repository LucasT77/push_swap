/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:02:48 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/15 16:21:40 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int		int_strlen(const char *s);
int		char_to_int(char *str, int *num);
int		error_checker(int argc, char **argv);
int		*string_to_array(int argc, char **argv, int *boo);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_array(int *array, int size);

void	swap(int **stack);
void	push(int **taken, int **given, int size_taken, int size_given);
void	rotate(int **stack, int size);
void	reverse_rotate(int **stack, int size);
void	selector(int **stack_a, int **stack_b, int **sizes, char *op);

#endif
