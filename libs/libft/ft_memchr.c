/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:06:09 by cmeng             #+#    #+#             */
/*   Updated: 2022/10/19 13:25:33 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr1;

	ptr1 = (unsigned char *) s;
	while (n > 0)
	{
		if (*ptr1 != (unsigned char) c)
		{
			ptr1++;
			n--;
		}
		else
			return (ptr1);
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "ABCDEFGH";
// 	int	a;
// 	a = 20;
// 	printf("%s", ft_memchr(str1, 'E', a));
// }