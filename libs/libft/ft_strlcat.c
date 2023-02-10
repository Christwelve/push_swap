/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:14:32 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/09 17:34:31 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (len_dst > dstsize)
		return (len_src + dstsize);
	i = 0;
	while ((len_dst + i < (dstsize - 1)) && (src[i]))
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}

// #include <string.h>

// int main(void)
// {
// 	size_t size = 0;
// 	char src[] = "nyan !";
// 	// char dst[100];
// 	printf("%zu", ft_strlcat(NULL, src, size));
// 	printf("%zu", strlcat(NULL, src, size));
// 	return (0);
// }