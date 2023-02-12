/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:05 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/12 16:23:58 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mallocp(size_t count, void **ptr)
{
	*ptr = malloc(count);
	if (*ptr == NULL)
		return (1);
	return (0);
}
