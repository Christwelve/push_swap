/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:01 by cmeng             #+#    #+#             */
/*   Updated: 2023/04/04 16:39:29 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libs.h"
# include <limits.h> 

typedef struct s_circle
{
	int				*elements;
	size_t			size;
	size_t			max_size;
	unsigned long	start;

}	t_circle;

/*
 	┌─────────────────────────────────────────────────────────────────────────┐
 	│ Algorithms                                                              │
 	└─────────────────────────────────────────────────────────────────────────┘
 */

void			radix_sort(t_circle *stack_a, t_circle *stack_b, size_t size);
void			five_sort(t_circle *stack_a, t_circle *stack_b);
void			simple_sort(t_circle *stack_a);

/*
 	┌─────────────────────────────────────────────────────────────────────────┐
 	│ Checker	                                                              │
 	└─────────────────────────────────────────────────────────────────────────┘
 */

void			do_op(char *in, t_circle *c_stack_a, t_circle *c_stack_b);
void			set_instructions(t_circle *c_stack_a, t_circle *c_stack_b);
int				is_stack_ok(t_circle *stack_a, size_t size);


/*
	┌─────────────────────────────────────────────────────────────────────────┐
	│ Utils                                                                   │
	└─────────────────────────────────────────────────────────────────────────┘
 */

void			std_error(void);
int				is_dup(int *stack, size_t size);
int				is_num(char *str);
int				int_max(long n);
int				dynamic_arr(int **res, int n);

int				is_sorted(int *stack, size_t size);
int				get_pos(int *values, size_t i, size_t size);
void			fill_stack(t_circle *stack, int *values, size_t size);

int				create_stack(t_circle *stack, size_t size);
unsigned int	calc_index(t_circle *stack, long index);
void			add_element(t_circle *stack, int element, long index);
int				get_element(t_circle *stack, long index);

/*
	┌─────────────────────────────────────────────────────────────────────────┐
	│ Operations                                                              │
	└─────────────────────────────────────────────────────────────────────────┘
 */

void			swap(t_circle *stack);
void			sa(t_circle *stack);
void			sb(t_circle *stack);
void			ss(t_circle *stack_a, t_circle *stack_b);

void			push(t_circle *stack_a, t_circle *stack_b);
void			pa(t_circle *stack_a, t_circle *stack_b);
void			pb(t_circle *stack_a, t_circle *stack_b);

void			rotate(t_circle *stack);
void			ra(t_circle *stack);
void			rb(t_circle *stack);
void			rr(t_circle *stack_a, t_circle *stack_b);

void			reverse_rotate(t_circle *stack);
void			rra(t_circle *stack_a);
void			rrb(t_circle *stack_b);
void			rrr(t_circle *stack_a, t_circle *stack_b);

#endif