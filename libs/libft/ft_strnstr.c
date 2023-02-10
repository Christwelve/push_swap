/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:39:11 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/09 16:54:01 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *) haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while ((haystack[i] == needle[i] && i < len) || needle[i] == '\0')
		{
			if (needle[i] == '\0')
				return ((char *) haystack);
			i++;
		}
		len--;
		haystack++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	haystack[100] = "Testprogramm";
// 	const char	needle[] = "";
// 	int		len = 2;

// 	printf("%s\n", ft_strnstr(haystack, needle, len));

// }