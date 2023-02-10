/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:39:20 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/02 12:47:45 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char		*ptr_src;
	char			*ptr_dst;
	unsigned int	i;

	ptr_src = src;
	ptr_dst = dst;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((i < dstsize - 1) && (ptr_src[i] != '\0'))
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	ptr_dst[i] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	int size = 3;
// 	char src[] = "Haus12345";
// 	char dst[size];
// 	ft_strlcpy(dst, src, size);
// 	printf("%s", dst);
// 	return (0);
// }