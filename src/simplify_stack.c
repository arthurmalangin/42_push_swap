/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:23:23 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 19:49:22 by amalangi         ###   ########.fr       */
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
	i = 0;
	while (stack)
	{
		copy[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (copy);
}

void	display_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
}

void	simplify_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		*copy;
	int		j;

	tmp = *stack;
	copy = copy_stack(tmp);
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
}
