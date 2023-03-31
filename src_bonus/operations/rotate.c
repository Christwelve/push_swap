/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:52 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/31 15:47:56 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_circle *stack)
{
	int	element;

	if (stack->size < 2)
		return ;
	element = get_element(stack, 0);
	stack->start = calc_index(stack, 1);
	add_element(stack, element, stack->size - 1);
}

void	ra(t_circle *stack_a)
{
	rotate(stack_a);
}

void	rb(t_circle *stack_b)
{
	rotate(stack_b);
}

void	rr(t_circle *stack_a, t_circle *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
