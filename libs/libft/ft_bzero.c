/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:24:58 by cmeng             #+#    #+#             */
/*   Updated: 2022/10/25 09:54:32 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr1;

	ptr1 = (char *) s;
	while (n > 0)
	{
		*ptr1++ = '\0';
		n--;
	}
}

// int	main(void)
// {
// 	char	str1[] = "ABCDEFGH";
// 	int	a;
// 	a = 3;
// 	ft_bzero(str1, a);
// 	printf("%s", str1);
// }