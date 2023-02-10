/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:44:21 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/09 11:43:06 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	if (src == dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}

// int main(void)
// {
// 	char src[20] = "Test";
// 	char dst[20];
// 	int n;

// 	n = 2;
// 	printf("%s", ft_memcpy(dst, src, n));
// }
