/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:46:27 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/23 21:07:43 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	create_stack(t_circle *stack, size_t size)
{
	if (ft_calloc2(size, sizeof(int), (void **)&stack))
		return (1);
	stack->size = 0;
	stack->start = 0;
	stack->max_size = size;
	return (0);
}

unsigned int	calc_index(t_circle *stack, long index)
{
	return ((index + stack->start + stack->max_size) % stack->max_size);
}

void	add_element(t_circle *stack, int element, unsigned long index)
{
	index = calc_index(stack, index);
	stack->elements[index] = element;
}

int	get_element(t_circle *stack, unsigned long index)
{
	index = calc_index(stack, index);
	return (stack->elements[index]);
}
