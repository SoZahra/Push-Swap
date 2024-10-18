/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:03:59 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:32:27 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcule le coût de déplacement de chaque 
// élément de la pile B vers la bonne
// position dans la pile A.
// Deux coûts sont calculés :
// cost_b représente le coût pour amener 
// l'élément en haut de la pile B
// cost_a représente le coût pour arriver 
// à la bonne position dans la pile A.
// Si l'élément est dans la moitié inférieure 
// de la pile, le coût sera négatif,
// s'il est dans la moitié supérieure, le coût est positif.

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

// Trouve l'élément de la pile B avec le coût 
// le moins cher pour le déplacer vers la pile A.

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
