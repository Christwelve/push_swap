/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:42:26 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/02 15:23:47 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*ptr_src;
	char			*ptr_dst;

	ptr_src = (char *) src;
	ptr_dst = (char *) dst;
	if (src == dst)
		return (dst);
	if (len == 0)
		return (dst);
	if (src < dst)
	{
		ptr_src = src + (len -1);
		ptr_dst = dst + (len -1);
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	else
		while (len--)
			*ptr_dst++ = *ptr_src++;
	return (dst);
}

// int	main(void)
// {
// 	char	src[] = "Hausfasdfsdfsdfsdf";
// 	char	dst[] = "StrasseStrasse";
// 	int	n = 2;

// 	printf("%s", ft_memmove(dst, src, n));
// 	return (0);
// }