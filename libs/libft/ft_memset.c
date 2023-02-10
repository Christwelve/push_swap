/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:37:02 by cmeng             #+#    #+#             */
/*   Updated: 2022/10/13 15:56:50 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr1;

	ptr1 = (char *) b;
	while (len > 0)
	{
		*ptr1++ = (unsigned char)c;
		len--;
	}
	return (b);
}

// int main(void)
// {
// 	char	str1[] = "ABCDEFGH";
// 	int	a;
// 	a = 3;
// 	printf("%s", ft_memset(str1, '2', a));
// }