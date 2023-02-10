/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:31:05 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/08 09:49:13 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		start;
// 	int		end;
// 	int		len;

// 	len = ft_strlen(s1);
// 	start = 0;
// 	end = len - 1;
// 	while (s1[start] && ft_strchr(set, s1[start]))
// 		start++;
// 	while (s1[end] && ft_strchr(set, s1[end - 1]))
// 		end--;
// 	return (ft_substr(s1, start, (end - start)));
// }

// int	main(void)
// {
// 	char const	str1[] = "____Testprogram__";
// 	char const	set[] = "_";

// 	printf("%s\n", ft_strtrim(str1, set));
// }
