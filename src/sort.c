/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:23:39 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 19:27:12 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pousse tous les éléments de la pile a 
// dans la pile b, sauf les trois derniers.
// Pousse d'abord les valeurs les plus petites, 
// puis les valeurs les plus grandes pour aider 
// a efficacité du tri.

static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

// Une fois la majeure partie de la pile triée, 
// déplace la pile a jusqu'au plus bas
// la valeur est en haut. S'il se trouve dans 
// la moitié inférieure de la pile, inversez
// faire pivoter, sinon faites-le pivoter 
// jusqu'à ce qu'il soit en haut du empiler.
// elle est appelée lorsque la majeure partie de 
// la pile est déjà triée et que l'on souhaite déplacer 
// la valeur la plus basse en haut pour continuer le tri.

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

// Algorithme de tri pour une pile supérieure à 3.
// Pousser tout sauf 3 chiffres pour empiler B.
// Triez les 3 nombres restants dans la pile A.
// Calculer le moove le plus rentable.
// Décaler les éléments jusqu'à ce que la pile A soit en ordre.

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
