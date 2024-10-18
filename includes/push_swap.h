/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:27:39 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:49:54 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Initiaisation

t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

// algo de sort 

int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

// Position

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

// Cout 

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);

// Calcul de moove

void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);

//moove

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

// Stack Functions

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

// Utils

void		free_s(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

// Error

void		exit_error(t_stack **stack_a, t_stack **stack_b);

// Input Checker

int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nb_str_cmp(const char *s1, const char *s2);

#endif