/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:53:06 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/30 20:07:05 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_circle *stack_a, t_circle *stack_b, size_t size)
{
	int		pos;
	int		digit;
	size_t	i;

	pos = 0;
	while ((1 << pos) <= stack_a->max_size)
	{
		i = 0;
		if (!same_digits(size, stack_a, pos))
		{
			while (i < size)
			{
				digit = stack_a->elements[stack_a->start] & (1 << pos);
				if (digit == 0)
					pb(stack_a, stack_b);
				else
					ra(stack_a);
				i++;
			}
		}
		while (stack_b->size)
			pa(stack_a, stack_b);
		pos++;
	}
}

void	five_sort(t_circle *stack_a, t_circle *stack_b)
{
	while (stack_a->size > 3)
	{
		if (stack_a->elements[stack_a->start] < 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	simple_sort(stack_a);
	if (stack_b->elements[calc_index(stack_b, 0)]
		< stack_b->elements[calc_index(stack_b, 1)])
		sb(stack_b);
	while (stack_b->size)
		pa(stack_a, stack_b);
}

void	simple_sort(t_circle *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->elements[calc_index(stack_a, 0)];
	b = stack_a->elements[calc_index(stack_a, 1)];
	c = stack_a->elements[calc_index(stack_a, 2)];
	if ((a > b) && (b > c) && (a > c))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((a > b) && (b < c) && (a < c))
		sa(stack_a);
	else if ((a < b) && (b > c) && (a < c))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((a > b) && (b < c) && (a > c))
		ra(stack_a);
	else if ((a < b) && (b > c) && (a > c))
		rra(stack_a);
}
