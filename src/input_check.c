/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:16:59 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 14:14:22 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check si l'argument est un nb, sinon il retourne 0. 

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

// Il check si dans la liste d'aurgument il y a des doublons. 
// return 1 si y a un double sinon 0.

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nb_str_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Vérifie que l'argument est un 0 pour 
// éviter les doublons 0  +0 -0
// et 0 0000 +000 -00000000 également.
// Retour : 1 si l'argument est un zéro, 
// 0 s'il contient autre chose qu'un zéro.

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

// Vérifie si les arguments donnés sont tous des nombres, sans doublons.

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
