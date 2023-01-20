/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:02:48 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/20 14:59:44 by luaraujo         ###   ########.fr       */
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
void	print_array(int *array, int size);

void	swap(int **stack);
void	push(int **taken, int **given, int size_taken, int size_given);
void	rotate(int **stack, int size);
void	reverse_rotate(int **stack, int size);
void	selector(int **stack_a, int **stack_b, int **sizes, char *op);

int		check(int **stack, int size);
void	sort_for3(char which, int **stack, int size);
int		little(int **stack, int init, int end);
void	minor_to_top(int which, int **stack, int size);
void	sort_for5(int **stack_a, int **stack_b, int **sizes);
int		minor(int *stack, int size);
int		*to_naturals(int *stack, int size);

#endif
