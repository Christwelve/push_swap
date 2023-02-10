/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:01:31 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/05 15:21:51 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr1;
	size_t		length_s1;
	size_t		length_s2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	ptr1 = ft_calloc((length_s1 + length_s2 + 1), sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	ft_strlcpy(ptr1, s1, length_s1 + 1);
	ft_strlcpy((ptr1 + length_s1), s2, length_s2 + 1);
	return (ptr1);
}

// int	main(void)
// {
// 	char const	str1[] = "Test";
// 	char const	str2[] = "programm";

// 	printf("%s", ft_strjoin(str1, str2));
// 	return (0);
// }
