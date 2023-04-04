/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/04/04 16:47:01 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_input(char **argv)
{
	long	n;
	char	**split;
	char	**cpy;

	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
		if (split == NULL || *split == NULL)
			return (free(split), 1);
		cpy = split;
		while (*split != NULL)
		{
			n = ft_atol(*split);
			if (is_num(*split) || int_max(n))
				return (ft_free2((void **) cpy), 1);
			split++;
		}
		ft_free2((void **) cpy);
	}
	return (0);
}

int	parse(char **argv, int **values, size_t *size)
{
	int		i;
	char	**split;
	char	**cpy;

	i = 0;
	if (ft_mallocp(1 * sizeof(int), (void **) values))
		return (1);
	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
		if (split == NULL || *split == NULL)
			return (free(split), 1);
		cpy = split;
		while (*split != NULL)
		{
			if (dynamic_arr(values, ft_atol(*split)))
				return (free(*values), ft_free2((void **) cpy), 1);
			split++;
			i++;
		}
		ft_free2((void **) cpy);
	}
	*size = i;
	return (0);
}

static void	select_algo(size_t size, t_circle *stack_a, t_circle *stack_b)
{
	if (size <= 3)
		simple_sort(stack_a);
	else if (size == 5)
		five_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, size);
}

static void	free_all(int *values, t_circle *stack_a, t_circle *stack_b)
{
	free(values);
	free(stack_a->elements);
	free(stack_b->elements);
}

int	main(int argc, char **argv)
{
	t_circle	stack_a;
	t_circle	stack_b;
	int			*values;
	size_t		size;

	if (argc < 2)
		return (0);
	if (check_input(argv))
		return (std_error(), 1);
	if (parse(argv, &values, &size))
		return (free(values), std_error(), 2);
	if (is_dup(values, size))
		return (free(values), std_error(), 3);
	if (is_sorted(values, size))
		return (free(values), 4);
	if (create_stack(&stack_a, size))
		return (free(values), std_error(), 5);
	if (create_stack(&stack_b, size))
		return (free(values), free(stack_a.elements), std_error(), 6);
	fill_stack(&stack_a, values, size);
	select_algo(size, &stack_a, &stack_b);
	free_all(values, &stack_a, &stack_b);
	return (0);
}
