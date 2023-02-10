/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:58 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/03 10:35:49 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	len = ft_strlen(s);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char			s[] = "Testprogramm";
// 	unsigned int	i = 2;
// 	printf("%s\n", ft_strmapi(s, f(i, f)));
// }

// "TEST"

// f -> to_upper(unsigned int i, char c) { return ft_toupper(c); }

// i = i + 5;