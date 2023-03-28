/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/28 02:04:29 by cmeng            ###   ########.fr       */
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

static int	parse(char **argv, int **values, size_t *size)
{
	int		i;
	char	**split;

	i = 0;
	if (ft_mallocp(1 * sizeof(int), (void **) values))
		return (1);
	while (*(++argv) != NULL)
	{
		split = ft_split(*argv, ' ');
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

void	fill_stack(t_circle *stack, int *values, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		stack->elements[i] = get_pos(values, i, size);
		i++;
	}
	stack->size = size;
}

/*
  ┌─────────────────────────────────────────────────────────────────────────┐
  │ dev tools                                                               │
  └─────────────────────────────────────────────────────────────────────────┘
 */

// static void	print_stacks(t_circle *stack_a, t_circle *stack_b, size_t size)
// {
// 	printf("\n%s\n", "pos   |stack_a| stack_b");
// 	printf("%s\n", "------|-------|---------");
// 	size_t j = 0;
// 	while (j < size)
// 	{
// 		printf("%zu     |", j);
// 		printf("%i      |", get_pos(stack_a->elements, j, size));
// 		printf("%i	|\n", stack_b->elements[j]);
// 		j++;
// 	}
// }

// void    print_stack(t_circle *stack, size_t size)
// {
//     if (stack->size == 0)
//     {
//         printf("                    ");
//         return ;
//     }
//     for (unsigned long i = 0; i < size; i++)
//     {
//         if ((i >= stack->start && i <= stack->start + stack->size - 1) || (stack->start + stack->size > size && i <= calc_index(stack, stack->size - 1)))
//             printf("%d ", get_element(stack, i - stack->start));
//         else
//             printf("  ");
//     }
// }

// void    print_indices(size_t size)
// {
//     printf("\n");
//     printf("\n");
//     for (size_t i = 0; i < size; i++)
//         printf("%zu ", i);
//     printf("    ");
//     for (size_t i = 0; i < size; i++)
//         printf("%zu ", i);
//     printf("\n");
// }

// void    print_stacks(t_circle *stack1, t_circle *stack2, size_t size)
// {
//     print_stack(stack1, size);
//     printf("    ");
//     print_stack(stack2, size);
//     printf("\n");
//     printf("\n");
// }

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

void	simple_sort(t_circle *stack_a)
{
	if ((stack_a->elements[0] > stack_a->elements[1])
		&& (stack_a->elements[1] > stack_a->elements[2]))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((stack_a->elements[0] > stack_a->elements[1])
		&& (stack_a->elements[1] < stack_a->elements[2]))
		sa(stack_a);
	else if ((stack_a->elements[0] < stack_a->elements[1])
		&& (stack_a->elements[1] > stack_a->elements[2]))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((stack_a->elements[0] > stack_a->elements[1])
		&& (stack_a->elements[1] < stack_a->elements[2]))
		ra(stack_a);
	else if ((stack_a->elements[0] < stack_a->elements[1])
		&& (stack_a->elements[1] > stack_a->elements[2]))
		rra(stack_a);
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
		return (std_error(), 2);
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
	else
		radix_sort(&stack_a, &stack_b, size);
	return (0);
}
