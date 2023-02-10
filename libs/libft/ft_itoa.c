/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:56:36 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/08 14:26:20 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	amount_characters(int n);

char	*ft_itoa(int n)
{
	char	*output;
	int		size;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = amount_characters(n);
	output = ft_calloc((size + 1), sizeof(char));
	if (!output)
		return (NULL);
	negative = 0;
	if (n < 0)
	{
		n *= (-1);
		output[0] = '-';
		size -= 1;
		negative = 1;
	}
	while (size)
	{
		output[size - 1 + negative] = n % 10 + '0';
		size--;
		n = n / 10;
	}
	return (output);
}

int	amount_characters(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	int i = 3;
// 	printf("output: %s\n", ft_itoa(i));
// 	return (0);
// }
