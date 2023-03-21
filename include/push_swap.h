/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:01 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/21 14:10:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libs.h"

typedef struct s_circle
{
	int				*elements;
	size_t			size;
	size_t			max_size;
	unsigned long	start;

}	t_circle;

int				is_dup(int *stack);
int				is_num(char *str);
int				int_max(long n);
int				get_int_len(int *arr);
int				dynamic_arr(int **res, int n);
int				create_stack(t_circle *stack, size_t size);
unsigned int	calc_index(t_circle *stack, long index);
int				add_element(t_circle *stack, int element, unsigned long index);
int				get_element(t_circle *stack, unsigned long index);



#endif