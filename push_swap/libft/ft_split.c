/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:04:41 by luaraujo          #+#    #+#             */
/*   Updated: 2023/01/27 17:18:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char chr)
{
	if (chr == ' ' || chr == '\t' || chr == '\n')
		return (1);
	else
		return (0);
}

static void	copy_words(char const *src, int len, char **str)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*str)[i] = src[i];
		i++;
	}
	(*str)[i] = '\0';
}

static int	num_of_words(char const *s)
{
	int	i;
	int	words;
	int	new;

	i = 0;
	new = 0;
	words = 0;
	while (s[i])
	{
		if (is_space(s[i]))
			new = 1;
		if (!is_space(s[i]) && (new == 1 || i == 0))
		{
			words++;
			new = 0;
		}
		i++;
	}
	return (words);
}

static char	**ft_split_aux(char const *s, int words, char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < words)
	{
		while (is_space(*s))
			s++;
		while (!is_space(s[len]) && s[len] != '\0')
			len++;
		if (len > 0)
		{
			str[i] = malloc(sizeof(char) * (len + 1));
			if (!str[i])
				return (0);
			copy_words(s, len, &str[i]);
			s += len;
			len = 0;
		}
		i++;
	}
	str[words] = NULL;
	return (str);
}

char	**ft_split(char const *s)
{
	char	**str;
	int		words;

	if (!s)
		return (0);
	words = num_of_words(s);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	str = ft_split_aux(s, words, str);
	return (str);
}
