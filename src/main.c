/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:17:27 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:50:33 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Vérifie si une pile est triée.
// Renvoie 0 si la pile n'est pas triée, 
// 1 si elle est triée.

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Choisit une méthode de tri en fonction du nombre
// de valeurs à trier.

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

// Vérifie si l'entrée est correcte, auquel cas 
// il initialise les piles a et b,
// attribue à chaque valeur des index 
// et trie les piles. Une fois le tri effectué, 
// libère les piles et les sorties.

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_s(&stack_a);
	free_s(&stack_b);
	return (0);
}
