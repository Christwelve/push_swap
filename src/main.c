/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/11 14:52:21 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			ft_check_input(char **argv);
static int	ft_check_num(char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (ft_check_input(argv))
		return (ft_printf("%s\n", "Error"), 1);
	return (0);
}

// split / check num / check max int / check dups ll /
int	ft_check_input(char **argv)
{
	int		i;
	char	**split;
	t_list	**head;
	t_list	*node;

	i = 0;
	split = NULL;
	head = NULL;
	node = NULL;
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		while (*split != NULL)
		{
			if (ft_check_num(*split))
				return (1);
			if (ft_atol(*split) < INT32_MIN || ft_atol(*split) > INT32_MAX)
				return (1);
			node = ft_lstnew((void *)ft_atol(*split));
			ft_lstadd_back(head, node);
			ft_printf("%i\n", node->content);
			// ft_printf("%s\n", *split++);
			// ft_printf("%s\n", n);
			split++;

			// break ;
		}
	}
	return (0);
}

// valid (0): number with max one sign (+/-)
static int	ft_check_num(char *str)
{
	int	i;
	int	sign;
	int	nums;

	i = 0;
	sign = 0;
	nums = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			sign++;
		if (str[i] >= '0' && str[i] <= '9')
			nums++;
		i++;
	}
	if ((nums == 0 || (nums != 0 && sign > 1)))
		return (1);
	return (0);
}
