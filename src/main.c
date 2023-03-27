/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/27 18:52:48 by cmeng            ###   ########.fr       */
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

void    print_stack(t_circle *stack, size_t size)
{
    if (stack->size == 0)
    {
        printf("                    ");
        return ;
    }
    for (unsigned long i = 0; i < size; i++)
    {
        if ((i >= stack->start && i <= stack->start + stack->size - 1) || (stack->start + stack->size > size && i <= calc_index(stack, stack->size - 1)))
            printf("%d ", get_element(stack, i - stack->start));
        else
            printf("  ");
    }
}

void    print_indices(size_t size)
{
    printf("\n");
    printf("\n");
    for (size_t i = 0; i < size; i++)
        printf("%zu ", i);
    printf("    ");
    for (size_t i = 0; i < size; i++)
        printf("%zu ", i);
    printf("\n");
}

void    print_stacks(t_circle *stack1, t_circle *stack2, size_t size)
{
    print_stack(stack1, size);
    printf("    ");
    print_stack(stack2, size);
    printf("\n");
    printf("\n");
}

void	radix_sort(t_circle *stack_a, t_circle *stack_b, size_t size)
{
	size_t	max;
	int		pos;
	int		digit;
	size_t	i;

	max = stack_a->max_size;
	pos = 0;
	while ((1 << pos) <= stack_a->max_size)
	{
		i = 0;
		if (!same_digits(size, stack_a, pos))
		{
			while (i < size)
			{
				digit = stack_a->elements[stack_a->start] & (1 << pos);
				printf("v: %i	", stack_a->elements[stack_a->start]);
				printf("d: %i	", digit);
				printf("bit : %i	", (1 << pos));
				printf("pos: %i	", pos);
				if (digit == 0)
					ra(stack_a);
				else
					pb(stack_a, stack_b);
				i++;
			}
		}
		print_indices(size);
		print_stacks(stack_a, stack_b, size);
		printf("start: %zu	", stack_a->start);
		printf("start: %zu\n\n--------------------------\n", stack_b->start);

		i = 0;
		size_t b_size = stack_b->size;
		while (i < b_size)
		{
			pa(stack_a, stack_b);
			i++;
		}
		print_indices(size);
		print_stacks(stack_a, stack_b, size);
		printf("start: %zu\n\n--------------------------\n", stack_a->start);
		pos++;
	}
}

int	main(int argc, char **argv)
{
	t_circle	stack_a;
	t_circle	stack_b;
	int			*values;
	size_t		size;


	if (argc < 2)
		return (1);
	if (check_input(argv))
		return (ft_printf("%s\n", "Error"), 1);
	if (parse(argv, &values, &size))
		return (ft_printf("%s\n", "Error"), 2);
	if (is_dup(values))
		return (free(values), ft_printf("%s\n", "Error"), 3);
	if (create_stack(&stack_a, size))
		return (free(values), ft_printf("%s\n", "Error"), 4);
	if (create_stack(&stack_b, size))
		return (free(values), free(stack_a.elements), ft_printf("%s\n", "Error"), 5);
	fill_stack(&stack_a, values, size);
	radix_sort(&stack_a, &stack_b, size);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// sa(&stack_a);
	// pa(&stack_a, &stack_b);
	// ra(&stack_a);
	// ra(&stack_a);
	print_indices(size);
	print_stacks(&stack_a, &stack_b, size);
	printf("start: %zu\n", stack_a.start);
	// ft_printf("%d\n", size);
	// ft_printf("%d\n", stack_a.start);
	// printf("%zu\n", stack_a.max_size);
	// printf("%zu\n", stack_b.max_size);


	return (0);
}
