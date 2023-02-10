/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:50:07 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/05 15:36:18 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr1;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr1 = ft_calloc((len + 1), sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	i = 0;
	while (i < (int) len && s[start + i] != '\0')
	{
		ptr1[i] = s[start + i];
		i++;
	}
	return (ptr1);
}

// int	main(void)
// {
// 	char	str[] = "Testprogramm";
// 	int 	start = 0;
// 	size_t 	len = 10;
// 	printf("%s\n", ft_substr(str, start, len));
// 	return (0);
// }