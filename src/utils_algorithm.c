/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:15:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/27 16:12:44 by cmeng            ###   ########.fr       */
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

// int itob(int decimal)
// {
//     int shift;
//     int binary;
//     int bit;
//     shift = 0;
//     binary = 0;
//     while (decimal > 0 && shift < 10)
//     {
//         bit = decimal & 2;
//         binary = binary | (bit << shift);
//         decimal = decimal / 2;
//         shift++;
//     }
//     return (binary);
// }