/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:26:05 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:30:15 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Échange les 2 premiers éléments d'une pile.
// Ne fait rien s'il n'y a qu'un ou aucun élément.

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

// Échange les 2 premiers éléments de la pile a.

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

// Échange les 2 premiers éléments de la pile b.

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

// Échange les 2 premiers éléments de la pile a 
// et les 2 premiers éléments de la pile b.

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
