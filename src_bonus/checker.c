/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:52 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/30 20:24:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	set_instructions(void)
{
	char	*in;

	in = NULL;
	int i = 0;
	// while (in)
	while (i < 10 )
	{
		// read(1, in, 20);
		in = get_next_line(1);
		ft_printf("checker: %s\n", in);
		i++;
	}
	// in = get_next_line(1);
	// ft_printf("%s", in);
	return (0);
}

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
	t_circle	c_stack_a;
	t_circle	c_stack_b;
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
	if (create_stack(&c_stack_a, size))
		return (free(values), std_error(), 4);
	if (create_stack(&c_stack_b, size))
		return (free(values), free(c_stack_a.elements), std_error(), 5);
	fill_stack(&c_stack_a, values, size);

	// print_indices(size);
	// print_stacks(&c_stack_a, &c_stack_b, size);
	// ft_printf("%i\n", c_stack_a.start);
	set_instructions();
	// if (is_sorted(&c_stack_a))
	// 	ft_printf("%s", "OK");
	// else
	// 	ft_printf("%s", "KO");
	return (0);
}
