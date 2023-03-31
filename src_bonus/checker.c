/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:52 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/31 15:46:43 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void do_op(char *in, t_circle *c_stack_a, t_circle *c_stack_b)
{	
	if(!ft_strncmp(in, "pa\n", 3))
		pa(c_stack_a, c_stack_b);
	if(!ft_strncmp(in, "pb\n", 3))
		pb(c_stack_a, c_stack_b);	
	if(!ft_strncmp(in, "sa\n", 3))
		sa(c_stack_a);	
	if(!ft_strncmp(in, "sb\n", 3))
		sb(c_stack_b);
	if(!ft_strncmp(in, "ss\n", 3))
		ss(c_stack_a, c_stack_b);
	if(!ft_strncmp(in, "ra\n", 3))
		ra(c_stack_a);
	if(!ft_strncmp(in, "rb\n", 3))
		rb(c_stack_b);
	if(!ft_strncmp(in, "rr\n", 3))
		rr(c_stack_a, c_stack_b);
	if(!ft_strncmp(in, "rra\n", 4))
		rra(c_stack_a);	
	if(!ft_strncmp(in, "rrb\n", 4))
		rrb(c_stack_b);
	if(!ft_strncmp(in, "rrr\n", 4))
		rrr(c_stack_a, c_stack_b);	
										
}

int	set_instructions(t_circle *c_stack_a, t_circle *c_stack_b)
{
	char	*in;

	in = NULL;
	while (1)
	{
		in = get_next_line(0);	
		if (in == NULL)
			break;
		do_op(in, c_stack_a, c_stack_b);
	}
	return (free(in), 0);
}

int	is_stack_ok(t_circle *stack_a, size_t size)
{
	size_t	i; 
	
	i = 0;
	while (i < size - 1)
	{
		if (stack_a->elements[calc_index(stack_a, size)] > stack_a->elements[calc_index(stack_a, size)+1])
			return(ft_printf("%s", "KO"), 1);
		i++;
	}
	ft_printf("%s", "OK");
	
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
	set_instructions(&c_stack_a, &c_stack_b);	
	is_stack_ok(&c_stack_a, size);

	// ft_printf("\n%s\n", "After Sorting");
	// print_indices(size);
	// print_stacks(&c_stack_a, &c_stack_b, size);
	// ft_printf("start_a:	%i\n", c_stack_a.start);
	// ft_printf("size_a:	%i\n", c_stack_a.size);
	
}	

	
// 	if (is_sorted(&c_stack_a, size))
// 		ft_printf("%s", "OK");
// 	else
// 		ft_printf("%s", "KO");
// 	return (0);
// }
