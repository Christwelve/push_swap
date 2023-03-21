/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:46 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/21 17:20:50 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_circle *stack)
{
	int	first;

	first = get_element(stack, 0);
	add_element(stack, get_element(stack, 1), 0);
	add_element(stack, first, 1);
}

void	sa(t_circle *stack_a)
{
	swap(stack_a);
	ft_printf("%s", "sa");
}

void	sb(t_circle *stack_b)
{
	swap(stack_b);
	ft_printf("%s", "sb");
}

void	ss(t_circle *stack_a, t_circle *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("%s", "ss");
}
