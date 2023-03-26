/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/26 20:45:09 by cmeng            ###   ########.fr       */
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

/*
  ┌─────────────────────────────────────────────────────────────────────────┐
  │ Position Approach                                                       │
  └─────────────────────────────────────────────────────────────────────────┘
 */

// static int	parse(char **argv, t_circle *stack_a, t_circle *stack_b)
// {
// 	int		i;
// 	char	**split;
// 	int		*a;

// 	i = 0;
// 	if (ft_mallocp(1 * sizeof(int), (void **) &a))
// 		return (1);
// 	while (*(++argv) != NULL)
// 	{
// 		split = ft_split(*argv, ' ');
// 		while (*split != NULL)
// 		{
// 			if (dynamic_arr(&a, ft_atol(*split)))
// 				return (free(a), 1);
// 			split++;
// 			i++;
// 		}
// 	}
// 	if (is_dup(a))
// 		return (free(a), 1);
// }
// 	// create_stack(stack_a, sizeof(int));
// 	// create_stack(stack_b, sizeof(int));
// 	// stack_a->max_size = i;
// 	// stack_b->max_size = i;
// 	stack_a->size = i;
// 	stack_b->size = i;

// 	if (ft_mallocp(i * sizeof(int), (void **) &stack_a->elements)
// 		|| ft_mallocp(i * sizeof(int), (void **) &stack_b->elements))
// 		return (1);

	// int j = 0;
	// while (a[j])
	// {
	// 	printf("Pos:    %i\n", get_pos(stack_a, a, a[j]));
	// 	stack_a->elements[j] = get_pos(stack_a, a, a[j]);
	// 	// ft_memset((void *) stack_a->elements, get_pos(stack_a, a, a[j]))
	// 	// stack_a->elements++;
	// 	j++;
	// }

// 	// if (ft_mallocp(i * sizeof(int), (void **) &stack_a->elements)
// 	// 	|| ft_mallocp(i * sizeof(int), (void **) &stack_b->elements))
// 	// 	return (1);
// 	ft_memcpy((void *) stack_a->elements, (const void *) a, i * sizeof(int));
// 	// print_stacks(stack_a, stack_b, i);
// 	return (free(a), 0);

// }

// static int	parse(char **argv, t_circle *stack_a, t_circle *stack_b)
// {
// 	int		i;
// 	char	**split;

// 	i = 0;
// 	if (ft_mallocp(1 * sizeof(int), (void **) &stack_a->values))
// 		return (1);
// 	while (*(++argv) != NULL)
// 	{
// 		split = ft_split(*argv, ' ');
// 		while (*split != NULL)
// 		{
// 			if (dynamic_arr(&stack_a->values, ft_atol(*split)))
// 				return (free(stack_a->values), 1);
// 			split++;
// 			i++;
// 		}
// 	}
// 	if (is_dup(stack_a->values))
// 		return (free(stack_a->values), 1);

// 	// int j = 0;
// 	// while(stack_a->values[j])
// 	// {
// 	// 	printf("Value:	%i\n", stack_a->values[j]);
// 	// 	j++;
// 	// }
// 	stack_a->max_size = i;
// 	stack_b->max_size = i;
// 	stack_a->size = i;
// 	stack_a->size = 0;

// 	if (ft_mallocp(i * sizeof(int), (void **) &stack_a->elements)
// 		|| ft_mallocp(i * sizeof(int), (void **) &stack_b->elements))
// 		return (1);
// 	size_t j = 0;
// 	while (j < stack_a->size)
// 	{
// 		// printf("Pos:    %i\n", get_pos(stack_a, stack_a->values, stack_a->values[j]));
// 		stack_a->elements[j] = get_pos(stack_a, stack_a->values, stack_a->values[j]);
// 		j++;
// 	}
// 	// ft_memcpy((void *) stack_a->elements, (const void *) stack_a->values, i * sizeof(int));
// 	return (0);
// }

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

int	get_pos(int *values, size_t i, size_t size)
{
	int		value;
	int		pos;
	size_t	j;

	j = 0;
	pos = 0;
	value = values[i];
	while (j < size)
	{
		if (values[j] < value)
			pos++;
		j++;
	}
	return (pos);
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

// static int	fill_stack(t_circle stack_a, t_circle stack_b)
// {

// }
// static int	parse(char **argv, t_circle *stack_a, t_circle *stack_b)
// {
// 	int		i;
// 	char	**split;
// 	int		*a;

// 	i = 0;
// 	if (ft_mallocp(1 * sizeof(int), (void **) &a))
// 		return (1);
// 	while (*(++argv) != NULL)
// 	{
// 		split = ft_split(*argv, ' ');
// 		while (*split != NULL)
// 		{
// 			if (dynamic_arr(&a, ft_atol(*split)))
// 				return (free(a), 1);
// 			split++;
// 			i++;
// 		}
// 	}
// 	if (is_dup(a))
// 		return (free(a), 1);
// 	if (ft_mallocp(i * sizeof(int), (void **) &stack_a->elements)
// 		|| ft_mallocp(i * sizeof(int), (void **) &stack_b->elements))
// 		return (1);
// 	ft_memcpy((void *) stack_a->elements, (const void *) a, i * sizeof(int));
// 	stack_a->size = i;
// 	stack_b->size = i;
// 	// print_stacks(stack_a, stack_b, i);
// 	return (free(a), 0);
// }


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
	int			*values;
	size_t		size;


	if (argc < 2)
		return (1);
	if (check_input(argv))
		return (ft_printf("%s\n", "Error"), 1);
	// if (parse(argv, &stack_a, &stack_b))
	// 	return (ft_printf("%s\n", "Error"), 1);
	if (parse(argv, &values, &size))
		return (ft_printf("%s\n", "Error"), 1);
	if (is_dup(values))
		return (free(values), 2);
	if (create_stack(&stack_a, size))
		return (free(values), 3);
	if (create_stack(&stack_b, size))
		return (free(values), free(stack_a.elements), 4);
	ft_printf("%d\n", size);
	fill_stack(&stack_a, values, size);

	print_stacks(&stack_a, &stack_b);


	// printf("\nis_sorted = %i\n", is_sorted(&stack_a));
	// printf("\nvalue	= %i", stack_a.elements[2]);
	// printf("\npos	= %i\n", get_pos(&stack_a, stack_a.elements[2]));

	return (0);
}
