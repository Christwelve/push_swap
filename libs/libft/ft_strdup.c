/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:15:24 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/08 10:45:04 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr1;
	int			len;

	len = ft_strlen(s1);
	ptr1 = ft_calloc((len + 1), sizeof(char));
	if (ptr1 == NULL)
	{
		return (NULL);
	}
	ft_strlcpy (ptr1, s1, len + 1);
	return (ptr1);
}

// int	main(void)
// {
// 	const char	str[] = "Testprogramm";

// 	printf("%s", ft_strdup(str));
// 	return (0);
// }