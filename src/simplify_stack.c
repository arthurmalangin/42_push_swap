/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:23:23 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/17 12:25:32 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*copy_stack(t_stack *stack)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * get_stack_size(stack));
	if (!copy)
	{
		ft_putstr_fd("Error\n", 1);
		return (NULL);
	}
	i = 0;
	while (stack)
	{
		copy[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (copy);
}

int	simplify_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		*copy;
	int		j;

	tmp = *stack;
	copy = copy_stack(tmp);
	if (!copy)
		return (0);
	copy = sort_tab(copy, get_stack_size(*stack));
	while (tmp)
	{
		j = 0;
		while (j < get_stack_size(*stack))
		{
			if (tmp->value == copy[j])
			{
				tmp->value = j;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
	free(copy);
	return (1);
}
