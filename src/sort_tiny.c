/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:23:03 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:29:40 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Renvoie l'index le plus élevé d'une pile.

static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

// Trie une pile de 3 nombres en 2 mouvements ou moins. 
// Le tri se fait par index plutôt que la valeur. 
// ---------Exemple:
// valeurs : 	 0   9   2
// indices : 	[1] [3] [2]
// Solution, 2 coups :
// rra :
// valeurs :	 2   0   9
// indices :	[2] [1] [3]
// sa :
// valeurs :	 0   2   9
// indices :	[1] [2] [3]

void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
