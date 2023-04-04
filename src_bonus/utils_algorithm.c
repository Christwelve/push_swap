/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:15:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/04/04 16:27:56 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(int *stack, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_pos(int *values, size_t i, size_t size)
{
	int		value;
	int		pos;
	size_t	j;

	j = 0;
	pos = 0;
	value = values[i];
	while (j < size)
	{
		if (values[j] < value)
			pos++;
		j++;
	}
	return (pos);
}

void	fill_stack(t_circle *stack, int *values, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		stack->elements[i] = get_pos(values, i, size);
		i++;
	}
	stack->size = size;
}
