/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/23 21:22:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_input(char **argv)
{
	long	n;
	char	**split;

	split = NULL;
	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
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

static int	parse(char **argv, t_circle *stack_a, t_circle *stack_b)
{
	int		i;
	char	**split;
	int		*a;

	i = 0;
	if (ft_mallocp(1 * sizeof(int), (void **) &a))
		return (1);
	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
		while (*split != NULL)
		{
			if (dynamic_arr(&a, ft_atol(*split)))
				return (free(a), 1);
			split++;
			i++;
		}
	}
	if (is_dup(a))
		return (free(a), 1);
	if (ft_mallocp(i * sizeof(int), (void **) &stack_a->elements)
		|| ft_mallocp(i * sizeof(int), (void **) &stack_b->elements))
		return (1);
	ft_memcpy((void *) stack_a->elements, (const void *) a, i * sizeof(int));
	stack_a->size = i;
	stack_b->size = i;
	// print_stacks(stack_a, stack_b, i);
	return (free(a), 0);
}


/*
  ┌─────────────────────────────────────────────────────────────────────────┐
  │ dev tool                                                                │
  └─────────────────────────────────────────────────────────────────────────┘
 */
static void	print_stacks(t_circle *stack_a, t_circle *stack_b)
{
	ft_printf("%s\n", "stack_a	| stack_b");
	ft_printf("%s\n", "--------|---------");
	size_t j = 0;
	while (j < stack_a->size)
	{
		ft_printf("%i	|", stack_a->elements[j]);
		ft_printf("%i	 |\n", stack_b->elements[j]);
		j++;
	}
}


int	main(int argc, char **argv)
{
	t_circle	stack_a;
	t_circle	stack_b;


	if (argc < 2)
		return (1);
	if (check_input(argv))
		return (ft_printf("%s\n", "Error"), 1);
	if (parse(argv, &stack_a, &stack_b))
		return (ft_printf("%s\n", "Error"), 1);
	print_stacks(&stack_a, &stack_b);

	printf("\nis_sorted = %i\n", is_sorted(&stack_a));
	printf("\nvalue	= %i", stack_a.elements[2]);
	printf("\npos	= %i\n", get_pos(&stack_a, stack_a.elements[2]));

	return (0);
}
