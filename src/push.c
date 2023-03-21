/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:57 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/21 16:43:50 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_circle *stack_a, t_circle *stack_b)
{
	t_circle	element;

	element = get_element(stack_a, 1);
	add_element(stack_b, element, -1);
	stack_a->start = calc_index(stack_a, 1);
	stack_b->start = calc_index(stack_b, -1);
	stack_a->size--;
	stack_b->size++;
}

void	pa(t_circle *stack_a, t_cirlce *stack_b)
{
	push(stack_a, stack_b);
	printf("%s", "pa");
}

void	pb(t_circle *stack_a, t_cirlce *stack_b)
{
	push(stack_b, stack_a);
	printf("%s", "pb");
}
