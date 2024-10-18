/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:22:47 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:29:15 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// L'élément supérieur de la pile est envoyé vers le bas.

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

// Envoie l'élément supérieur de la pile a vers le bas.

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

// Envoie l'élément supérieur de la pile b vers le bas.

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

// Envoie l'élément supérieur de la pile a et de la pile b vers le bas
// de leurs piles respectives.

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
