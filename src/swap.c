/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:37:46 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/16 17:52:31 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(stack_t stack)
{
	int	first;

	first = get_element(stack, 0);
	add_element(stack, get_element(stack, 1), 0);
	add_element(stack, first, 1);
}

void	sa(stack_t stack)
{
	swap(stack);
	ft_printf("%s", "sa");
}

void	sb(stack_t stack)
{
	swap(stack);
	ft_printf("%s", "sb");
}

void	ss(stack_t stack_a, stack_t stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("%s", "ss");
}
