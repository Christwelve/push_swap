/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:52 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/21 17:21:27 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_circle *stack)
{
	t_circle	element;

	element = get_element(stack, 0);
	stack->start = calc_index(stack, 1);
	add_element(stack, element, stack->size - 1);
}

void	ra(t_circle *stack_a)
{
	rotate(stack_a);
	printf("%s", "ra");
}

void	rb(t_circle *stack_b)
{
	rotate(stack_b);
	printf("%s", "rb");
}

void	rr(t_circle *stack_a, t_circle *stack_b)
{
	rotate(stack_a);
	rotate(stack_a);
	printf("%s", "rr");
}
