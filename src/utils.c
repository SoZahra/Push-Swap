/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:26:39 by fzayani           #+#    #+#             */
/*   Updated: 2024/07/17 16:50:11 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_s(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

// Écrit « Erreur\n » sur la sortie standard 
// après avoir libéré les piles a et b.
// Quitte avec le code d'erreur standard 1.

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_s(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_s(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

// Convertit une chaîne de caractères 
// alphanumériques en un entier long.

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// Renvoie la valeur absolue d'un nombre donné.
// La valeur absolue d'un nombre est utilisée 
// pour mesurer la distance de celui-ci
// nombre à partir de 0, qu'il soit positif 
// ou négatif (la valeur abs de -6 est 6).

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
