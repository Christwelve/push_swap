/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:01:14 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/21 14:10:20 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	int_max(long n)
{
	if (n < INT32_MIN || n > INT32_MAX)
		return (1);
	return (0);
}

int	is_dup(int *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_num(char *str)
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

int	dynamic_arr(int **res, int n)
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