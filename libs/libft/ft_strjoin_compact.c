/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_compact.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:36:45 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/10 10:31:35 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// edited: '\n' overwritten with src[ft_strlen(src) - 1] = 0

int	ft_strjoin_compact(char **dst, char *src)
{
	char	*new;
	int		len;

	len = ft_strlen(src);
	src[len] = 0;
	new = ft_strjoin(*dst, src);
	free(*dst);
	free(src);
	*dst = new;
	return (new == NULL);
}
