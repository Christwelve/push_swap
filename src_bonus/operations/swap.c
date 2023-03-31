/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:46 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/31 15:48:07 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_circle *stack)
{
	int	first;

	if (stack->size < 2)
		return ;
	first = get_element(stack, 0);
	add_element(stack, get_element(stack, 1), 0);
	add_element(stack, first, 1);
}

void	sa(t_circle *stack_a)
{
	swap(stack_a);
}

void	sb(t_circle *stack_b)
{
	swap(stack_b);
}

void	ss(t_circle *stack_a, t_circle *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
