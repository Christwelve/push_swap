/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:53:47 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/07 16:21:08 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int		count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (is_word)
				is_word = 0;
		}
		else
		{
			if (!is_word)
			{
				count++;
				is_word = 1;
			}
		}
		s++;
	}
	return (count);
}

static int	count_letters(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*cpy_word(char **s, char c)
{
	int			i;
	char		*out;

	i = 0;
	out = ft_calloc((count_letters(*s, c) + 1), sizeof(char));
	if (!out)
		return (NULL);
	while ((*s)[i] != c && (*s)[i] != '\0')
	{
		out[i] = (*s)[i];
		i++;
	}
	while ((*s)[i] && (*s)[i] == c)
		i++;
	*s += i;
	return (out);
}

static char	**free_all(char **out, int i)
{
	if (out == NULL)
		return (NULL);
	while (i)
	{
		free(out[i]);
		i--;
	}
	free(out);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*cpy;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	out = ft_calloc((count_words((char *)s, c) + 1), sizeof(char *));
	if (!out)
		return (NULL);
	cpy = (char *) s;
	while (*cpy && *cpy == c)
	{
		cpy++;
	}
	while (*cpy != '\0')
	{
		out[i] = cpy_word(&cpy, c);
		if (out[i] == NULL)
			return (free_all(out, i));
		i++;
	}
	out[i] = NULL;
	return (out);
}

// int	main(void)
// {
// 	char	str[] = "1234567890";
// 	char	c = 'm';
// 	char	**out = ft_split(str, c);

// 	while (*out != NULL)
// 		printf("%s_", *out++);
// 	printf("\n");
// 	// printf("%s\n", cpy_word(&str, c));
// 	printf("%d\n", count_words(str, c));
// 	// printf("%d\n", count_letters(str, c));
// 	return (0);
// }
