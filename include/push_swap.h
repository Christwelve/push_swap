/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:01 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/26 20:39:51 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libs.h"

typedef struct s_circle
{
    int             *values;
	int				*elements;
	size_t			size;
	size_t			max_size;
	unsigned long	start;

}	t_circle;

// typedef struct s_elements
// {
// 	int			value;
// 	size_t		pos;

// }	t_elements

/*
  ┌─────────────────────────────────────────────────────────────────────────┐
  │ Utils                                                                   │
  └─────────────────────────────────────────────────────────────────────────┘
 */
int				is_dup(int *stack);
int				is_num(char *str);
int				int_max(long n);
int				dynamic_arr(int **res, int n);

int				is_sorted(t_circle *stack);
// int				get_pos(t_circle *stack, int element);
// int				get_pos(t_circle *stack_a, int *a, int nbr);

int				create_stack(t_circle *stack, size_t size);
unsigned int	calc_index(t_circle *stack, long index);
void			add_element(t_circle *stack, int element, long index);
int				get_element(t_circle *stack, long index);

/*
  ┌─────────────────────────────────────────────────────────────────────────┐
  │ Operations                                                              │
  └─────────────────────────────────────────────────────────────────────────┘
 */
void			push(t_circle *stack_a, t_circle *stack_b);
void			pa(t_circle *stack_a, t_circle *stack_b);
void			pb(t_circle *stack_a, t_circle *stack_b);

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