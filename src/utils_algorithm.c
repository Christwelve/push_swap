/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:15:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/23 21:16:05 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_circle *stack)
{
	size_t	i;


	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->elements[i] > stack->elements[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_pos(t_circle *stack, int element)
{
	size_t	i;
	int		pos;

	i = 0;
	pos = 1;
	while (i < stack->size)
	{
		if (element > stack->elements[i])
			pos++;
		i++;
	}
	return (pos);
}