/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:46:54 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/01 20:04:04 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stacksize(t_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a == NULL || is_sorted(*stack_a))
        return;

    int size = stacksize(*stack_a);

    // Tant que la pile n'est pas triée
    while (!is_sorted(*stack_a))
    {
        if ((*stack_a)->value == find_min(*stack_a))  // Trouver le minimum
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }

    // Remettre les éléments dans stack_b dans stack_a
    while (*stack_b)
        pa(stack_a, stack_b);
}

// Fonction pour trouver la valeur minimale dans la pile
int find_min(t_stack *stack)
{
    int min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}
