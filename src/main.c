/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/10 11:44:24 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	// int		j;
	char	**split;
	char	*tmp;

	tmp = NULL;
	split = NULL;
	// if (ft_calloc2(1, 1, (void *) &tmp))
	// 	return (1);
	if (argc < 2)
		return (1);
	i = 1;
	// j = 0;
	while (i < argc)
	{
		tmp = ft_strtrim(argv[i], " ");
		// ft_printf("%s\n", tmp);
		split = ft_split(argv[i], ' ');
		while (*split != NULL)
			ft_printf("%s\n", *split++);
		// if (ft_strjoin_compact(input, tmp))
		// 	return (1);
		i++;
	}
	ft_printf("%s\n", argv[i]);
	return (0);
}

