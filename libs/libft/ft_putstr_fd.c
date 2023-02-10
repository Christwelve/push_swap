/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:31:40 by cmeng             #+#    #+#             */
/*   Updated: 2022/11/14 11:59:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd == 0)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

// int main(void)
// {
// 	char str[] = "Test";
// 	int	fd = 2;
// 	ft_putstr_fd(str, fd);
// 	return (0);
// }
