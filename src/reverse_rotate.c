/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:15:06 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/26 15:09:32 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_circle *stack)
{
	int	element;

	element = get_element(stack, stack->size - 1);
	stack->start = calc_index(stack, -1);
	add_element(stack, element, 0);
}

void	rra(t_circle *stack_a)
{
	reverse_rotate(stack_a);
	printf("%s\n", "rra");
}

void	rrb(t_circle *stack_b)
{
	reverse_rotate(stack_b);
	printf("%s\n", "rrb");
}

void	rrr(t_circle *stack_a, t_circle *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("%s\n", "rrr");
}
