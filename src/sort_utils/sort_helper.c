/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:18:01 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/21 02:46:53 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	else
	{
		return (n);
	}
}

int	get_approach_value(t_stack *stack, int value)
{
	long long int		current_difference;
	long long int		closest_value;
	long long int		closest_difference;
	t_stack	*tmp;

	tmp = stack;
	closest_value = 2147483660;
	closest_difference = ft_abs(value - closest_value);
	while (tmp)
	{
		current_difference = ft_abs(value - tmp->value);
		if ((current_difference < closest_difference && tmp->value > value)
			|| (current_difference == closest_difference
				&& tmp->value > closest_value))
		{
			closest_value = tmp->value;
			closest_difference = current_difference;
		}
		tmp = tmp->next;
	}
	return (closest_value);
}

int	is_sorted_reverse(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
