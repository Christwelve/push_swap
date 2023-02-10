/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:38:51 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/14 11:23:22 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		{
			if (s1[i] != s2[i])
				break ;
			i++;
		}
		return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	char str1[] = "ABCDEF";
// 	char str2[] = "ABCDRFS";
// 	int n;
// 	n = 2;

// 	printf("%d", ft_strncmp(str1, str2, n));
// 	return (0);
// }