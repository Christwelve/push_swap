/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:57 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/26 15:08:06 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_circle *stack_a, t_circle *stack_b)
{
	int	element;

	if (stack_b->size == 0)
		return ;
	element = get_element(stack_b, 0);
	stack_b->start = calc_index(stack_b, 1);
	stack_b->size--;
	add_element(stack_a, element, -1);
	stack_a->start = calc_index(stack_a, -1);
	stack_a->size++;
}

void	pa(t_circle *stack_a, t_circle *stack_b)
{
	printf("%s\n", "pa");
	push(stack_a, stack_b);
}

void	pb(t_circle *stack_a, t_circle *stack_b)
{
	printf("%s\n", "pb");
	push(stack_b, stack_a);
}
