/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:01 by cmeng             #+#    #+#             */
/*   Updated: 2023/02/15 14:30:09 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libs.h"

typedef struct s_data
{

}	t_data;

typedef struct s_circle
{
	int				*element;
	int				pos;
	size_t			size;
	size_t			max_size;
	unsigned long	start;

}	t_circle;

// typedef struct s_dynamic
// {
// 	int		*element;
// 	size_t	size;
// 	size_t	max_size;
// }	t_dynamic

#endif