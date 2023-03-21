/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:01 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/21 17:25:54 by cmeng            ###   ########.fr       */
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

void			push(t_circle *stack_a, t_circle *stack_b);
void			pa(t_circle *stack_a, t_cirlce *stack_b);
void			pb(t_circle *stack_a, t_cirlce *stack_b);

void			swap(t_circle *stack);
void			sa(t_circle *stack);
void			sb(t_circle *stack);
void			ss(t_circle *stack_a, t_circle *stack_b);

void			rotate(t_circle *stack);
void			ra(t_circle *stack);
void			rb(t_circle *stack);
void			rr(t_circle *stack_a, t_circle *stack_b);

void			reverse_rotate(t_circle *stack);
void			rra(t_circle *stack_a);
void			rrb(t_circle *stack_b);
void			rrr(t_circle *stack_a, t_circle *stack_b);

#endif