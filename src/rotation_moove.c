/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:10:47 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:33:16 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// L'inversion fait pivoter les piles A et B 
// jusqu'à ce que l'une d'elles soit en position.
// Le coût indiqué est négatif puisque les deux positions 
// sont dans la moitié inférieure de leurs piles respectives. 
// Le coût augmente à mesure que les piles sont
// pivoté, quand on atteint 0, la pile a été tournée au maximum
// et la position supérieure est correcte.

static void	rev_rotate_both(t_stack **a, t_stack **b,
											int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

// Fait pivoter les piles A et B jusqu'à ce que 
// l'une d'elles soit en position.
// Le coût donné est positif puisque les deux positions 
// sont dans la moitié supérieure de leurs piles respectives. 
// Le coût diminue à mesure que les piles sont
// pivoté, quand on atteint 0, la pile a été tournée au maximum
// et la position supérieure est correcte.

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

// Fait pivoter la pile A jusqu'à ce qu'elle soit en position. 
// Si le coût est négatif, la pile subira une rotation inversée, 
// si elle est positive, elle le sera tourné.

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

// Fait pivoter la pile B jusqu'à 
// ce qu'elle soit en position. Si le coût est négatif,
// la pile subira une rotation inversée, 
// si elle est positive, elle le sera tourné.

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

// Choisit le mouvement à effectuer pour amener 
// l'élément de la pile B au bon endroit, position dans la pile A.
// Si les coûts de déplacement des piles A et B 
// vers la position correspondent (cad les deux
// des deux positifs), les deux seront tournés 
// ou inversés en même temps.
// Ils peuvent également être tournés séparément, 
// avant de finalement pousser l'élément supérieur B.
// vers la pile supérieure A.

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}
