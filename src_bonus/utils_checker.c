/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:31:01 by christianme       #+#    #+#             */
/*   Updated: 2023/04/04 16:52:57 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_op(char *in, t_circle *c_stack_a, t_circle *c_stack_b)
{
	if (!ft_strncmp(in, "pa\n", 3))
		pa(c_stack_a, c_stack_b);
	if (!ft_strncmp(in, "pb\n", 3))
		pb(c_stack_a, c_stack_b);
	if (!ft_strncmp(in, "sa\n", 3))
		sa(c_stack_a);
	if (!ft_strncmp(in, "sb\n", 3))
		sb(c_stack_b);
	if (!ft_strncmp(in, "ss\n", 3))
		ss(c_stack_a, c_stack_b);
	if (!ft_strncmp(in, "ra\n", 3))
		ra(c_stack_a);
	if (!ft_strncmp(in, "rb\n", 3))
		rb(c_stack_b);
	if (!ft_strncmp(in, "rr\n", 3))
		rr(c_stack_a, c_stack_b);
	if (!ft_strncmp(in, "rra\n", 4))
		rra(c_stack_a);
	if (!ft_strncmp(in, "rrb\n", 4))
		rrb(c_stack_b);
	if (!ft_strncmp(in, "rrr\n", 4))
		rrr(c_stack_a, c_stack_b);
}

void	set_instructions(t_circle *c_stack_a, t_circle *c_stack_b)
{
	char	*in;

	in = NULL;
	while (1)
	{
		in = get_next_line(0);
		if (in == NULL)
			break ;
		do_op(in, c_stack_a, c_stack_b);
	}
    free(in);
}

int	is_stack_ok(t_circle *stack_a, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack_a->elements[stack_a->start + i % stack_a->size]
			> stack_a->elements[(stack_a->start + i + 1) % stack_a->size])
			return (ft_printf("%s\n", "KO"), 0);
		i++;
	}
	return (ft_printf("%s\n", "OK"), 1);
}
