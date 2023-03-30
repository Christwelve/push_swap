/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:15:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/30 20:07:22 by cmeng            ###   ########.fr       */
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

int	same_digits(size_t size, t_circle *stack_a, int pos)
{
	size_t	i;
	int		digit;
	int		tmp;

	i = 0;
	tmp = stack_a->elements[stack_a->start + i % stack_a->size] & (1 << pos);
	i++;
	while (i < size)
	{
		digit = stack_a->elements[stack_a->start + i % stack_a->size]
			& (1 << pos);
		if (tmp != digit)
			return (0);
		i++;
	}
	return (1);
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