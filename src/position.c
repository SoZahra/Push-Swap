/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:11 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:27:35 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Attribue une position à chaque élément 
// d'une pile de haut en bas dans l'ordre croissant.
// Exemple de pile :
// valeur :		 3   0   9   1
// indice :		[3] [1] [4] [2]
// pos	  :		<0> <1> <2> <3>
// Utilisé pour calculer le coût du déplacement 
// d'un nombre vers une certaine position. 
// Si l'exemple ci-dessus est la pile b, 
// cela coûterait rien (0) pour pousser 
// le premier élément à empiler a. Cependant, si nous voulons
// pousser la valeur la plus élevée, 9, qui est en troisième 
// position, cela coûterait 2 supplémentaires
// se déplace pour amener ce 9 au sommet de b 
// avant de le pousser pour empiler a.

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

// Obtient la position actuelle de l'élément 
// avec l'index le plus bas dans une pile.

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

// Sélectionne la meilleure position cible dans 
// la pile A pour l'index donné d'un élément dans la pile B. 
// Vérifie d'abord si l'index de l'élément B peut être placé 
// dans la pile A, en vérifiant s'il y a un élément dans la pile A 
// avec un indice plus grand. 
// Sinon, il trouve l'élément avec le plus petit indice 
// dans A et l'attribue comme position cible.
//	--- Exemple:
// 		target_pos commence à INT_MAX
// 		Indice B : 3
// 		A contient les index : 9 4 2 1 0
// 		9 > 3 && 9 < INT_MAX : target_pos mis à jour à 9
// 		4 > 3 && 4 < 9 : position cible mise à jour à 4
// 		2 < 3 && 2 < 4 : pas de mise à jour !
// Donc target_pos doit être la position de l'index 4, 
// puisqu'il s'agit de l'indice le plus proche.
//	--- Exemple:
// 		target_pos commence à INT_MAX
// 		Indice B : 20
// 		A contient des index : 16 4 3
// 		16 < 20 : pas de mise à jour ! cible_pos = INT_MAX
// 		4 < 20 : pas de mise à jour ! cible_pos = INT_MAX
// 		3 < 20 : pas de mise à jour ! cible_pos = INT_MAX
// il faut changer de stratégie :
// 		16 < 20 : target_pos mis à jour à 20
// 		4 < 20 : target_pos mis à jour à 4
// 		3 < 20 : target_pos mis à jour à 3
// Donc target_pos doit être la position de l'index 3, puisque c'est
// la "fin" de la pile.

static int	get_target(t_stack **a, int b_i,
								int target_i, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_i && tmp_a->index < target_i)
		{
			target_i = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_i != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_i)
		{
			target_i = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

// Attribue une position cible dans la pile A 
// à chaque élément de la pile A.
// La position cible est l'endroit où l'élément 
// en B doit accéder pour être trié correctement. 
// C'est utilisé pour calculer le coût 
// de déplacement de chaque élément vers
// sa position cible dans la pile A.

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		target_pos;

	tmp = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp)
	{
		target_pos = get_target(a, tmp->index, INT_MAX, target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp->next;
	}
}
