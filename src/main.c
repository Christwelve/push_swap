/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/11 10:09:24 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			ft_check_input(int argc, char **argv);
static int	ft_check_num(char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (ft_check_input(argc, argv))
		return (ft_printf("%s\n", "Error"), 1);
	return (0);
}

// split / check num / atoi / check dups ll /
int	ft_check_input(int argc, char **argv)
{
	int		i;
	long	n;
	char	**split;

	i = 0;
	n = 0;
	split = NULL;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (*split != NULL)
		{
			if (ft_check_num(*split))
				return (1);
			// break ;
			ft_printf("%s\n", *split++);
			// n = ft_atoi_long(*split);
			// ft_printf("%i", n);
		}
		n = ft_atoi_long(*split);
		ft_printf("%i", n);
		// if ((int)ints < INT32_MIN || (int)ints > INT32_MAX)
		// 	return (1);
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
	if ((nums == 0 && sign != 0) || (nums != 0 && sign > 1))
		return (1);
	return (0);
}
