/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/30 17:55:10 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_input(char **argv)
{
	long	n;
	char	**split;

	split = NULL;
	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
		if (*split == NULL)
			return (free(split), 1);
		while (*split != NULL)
		{
			n = ft_atol(*split);
			if (is_num(*split) || int_max(n))
				return (1);
			split++;
		}
	}
	return (0);
}

int	parse(char **argv, int **values, size_t *size)
{
	int		i;
	char	**split;

	i = 0;
	if (ft_mallocp(1 * sizeof(int), (void **) values))
		return (1);
	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
		if (*split == NULL)
			return (free(split), 1);
		while (*split != NULL)
		{
			if (dynamic_arr(values, ft_atol(*split)))
				return (free(*values), 1);
			split++;
			i++;
		}
	}
	*size = i;
	return (0);
}

int	main(int argc, char **argv)
{
	t_circle	stack_a;
	t_circle	stack_b;
	int			*values;
	size_t		size;

	if (argc < 2)
		return (0);
	if (check_input(argv) || parse(argv, &values, &size))
		return (std_error(), 1);
	if (is_dup(values, size))
		return (free(values), std_error(), 3);
	if (is_sorted(values, size))
		return (free(values), 3);
	if (create_stack(&stack_a, size))
		return (free(values), std_error(), 4);
	if (create_stack(&stack_b, size))
		return (free(values), free(stack_a.elements), std_error(), 5);
	fill_stack(&stack_a, values, size);
	if (size == 3)
		simple_sort(&stack_a);
	else if (size == 5)
		five_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b, size);
	return (0);
}
