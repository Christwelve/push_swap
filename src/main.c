/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/13 14:52:16 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			ft_check_input(char **argv);
static int	dynamic_arr(int **res, int n);
static int	ft_check_num(char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (ft_check_input(argv))
		return (ft_printf("%s\n", "Error"), 1);
	return (0);
}

// dynamic arr approach
int	ft_check_input(char **argv)
{
	int		i;
	long	n;
	char	**split;
	int		*stack_a;

	i = 0;
	split = NULL;
	if (ft_calloc2(1, sizeof(int), (void **) &stack_a))
		return (1);
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		while (*split != NULL)
		{
			n = ft_atol(*split);
			if (ft_check_num(*split))
				return (1);
			if (n < INT32_MIN || n > INT32_MAX)
				return (1);
			if (dynamic_arr(&stack_a, n))
				return (1);
			split++;
		}
	}
	// int j = 0;
	// ft_printf("%s	|\n", "stack_a");
	// ft_printf("%s\n", "--------|");
	// while(stack_a[j])
	// {
	// 	ft_printf("%i	|\n", stack_a[j]);
	// 	j++;
	// }
	return (0);
}

static int	dynamic_arr(int **res, int n)
{
	int			*tmp;
	static int	i = 0;
	static int	size = 1;

	if (i == size)
	{
		if (ft_calloc2(size * 2, sizeof(int), (void **) &tmp))
			return (1);
		ft_memcpy(tmp, *res, size * sizeof(int));
		free(*res);
		*res = tmp;
		size = size * 2;
	}
	(*res)[i++] = n;
	return (0);
}

// valid (0): number with max one sign (+/-)
static int	ft_check_num(char *str)
{
	int	i;
	int	has_sign;

	i = 0;
	has_sign = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		has_sign = 1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	if (has_sign && i == 1)
		return (1);
	return (0);
}

// linked list
// int	ft_check_input(char **argv)
// {
// 	int		i;
// 	char	**split;
// 	t_list	**lst;
// 	t_list	*node;

// 	i = 0;
// 	split = NULL;
// 	lst = NULL;
// 	node = NULL;
// 	while (argv[++i])
// 	{
// 		split = ft_split(argv[i], ' ');
// 		while (*split != NULL)
// 		{
// 			if (ft_check_num(*split))
// 				return (1);
// 			if (ft_atol(*split) < INT32_MIN || ft_atol(*split) > INT32_MAX)
// 				return (1);
// 			node = ft_lstnew((void *)ft_atol(*split));
// 			if (!node)
// 				return (1);
// 			ft_lstadd_back(lst, node);
// 			ft_printf("%i\n", node->content);
// 			split++;
// 		}
// 	}
// 	return (0);
// }


// int	ft_check_duplicates(t_list *node)
// {
// 	t_list	*cmp;

// 	while (node)
// 	{
// 		cmp = node->next;
// 		while (cmp)
// 		{
// 			if (node->content == cmp->content)
// 				return (1);
// 			cmp = cmp->next;
// 		}
// 	}
// 	return (0);
// }

// split / check num / check max int / check dups ll /
// int	ft_check_input(char **argv)
// {
// 	int			i;
// 	char		**split;
// 	// t_vector	stack_a;

// 	i = 0;
// 	split = NULL;
// 	while (argv[++i])
// 	{
// 		split = ft_split(argv[i], ' ');
// 		while (*split != NULL)
// 		{
// 			if (ft_check_num(*split))
// 				return (1);
// 			if (ft_atol(*split) < INT32_MIN || ft_atol(*split) > INT32_MAX)
// 				return (1);
// 			// split++;
// 			ft_printf("%s\n", *split++);
// 		}
// 		// if (stack_a->size > 0)
// 		// {
// 		// 	stack_a = malloc(stack_a->size * sizeof(int) + 1);

// 		// }
// 	}
// 	return (0);
// }

// HANDLE LINKED LISTS
// t_list *current;
// 	current = *head;
// 	while (current != NULL)
// 	{
// 		if (current->content > node->content
// 			i++;
// 		if (current->content == node->content)
// 			j++;
// 	}
// 	node

// 	i = 0;
// 	tmp = current node->content;

// 	if (tmp > node->content)
// 		i++;
// 	return (i);
