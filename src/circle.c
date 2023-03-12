/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:46:27 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/15 13:37:10 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_buf(t_circle *buf, size_t size)
{
	if (ft_mallocp(size, buf->element))
		return (1);
	buf->size = 0;
	buf->max_size = 0;
	buf->start = 0;
}

unsigned int	calc_index(t_circle *buf, unsigned long index)
{
	return ((index + buf->start) % buf->max_size);
}

int	add_element(t_circle *buf, int content)
{
	unsigned long	index;

	if (buf->size == buf->max_size)
		return (1);
	index = calc_index(buf, buf->size++);
	buf->content[index] = content;
	return (0);
}

int	get_content(t_circle *buf, unsigned long index)
{
	index = calc_index(buf, index);
	return (buf->content[index]);
}

int	main(void)
{
	t_circle	buf;

	

}