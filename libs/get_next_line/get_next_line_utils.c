/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/01/29 22:15:53 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_new(char *s1, char *s2, int in_len);

char	*ft_substr_new(char const *s, unsigned int start, size_t len)
{
	char			*ptr1;
	int				i;

	if (s == NULL)
		return (NULL);
	if (len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) + 1;
	ptr1 = ft_calloc((len + 1), sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	i = 0;
	while (i < (int) len && s[start + i] != '\0')
	{
		ptr1[i] = s[start + i];
		i++;
	}
	ptr1[i] = 0;
	return (ptr1);
}

char	*ft_strjoin_new(char *s1, char *s2, int in_len)
{
	char		*ptr1;
	size_t		len;
	size_t		i;
	size_t		j;

	if (s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + in_len;
	ptr1 = ft_calloc(len + 1, sizeof(char));
	if (ptr1 == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < (len - in_len))
			ptr1[i] = s1[i];
		else
			ptr1[i] = s2[j++];
		i++;
	}
	ptr1[len] = 0;
	free(s1);
	return (ptr1);
}
