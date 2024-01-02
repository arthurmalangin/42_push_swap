/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:46:54 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/02 01:11:52 by amalangi         ###   ########.fr       */
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
	int min_b;
	int max_b;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	min_b = find_min(*stack_b);
	max_b = find_max(*stack_b);
	if ((*stack_b)->value == min_b)
	{
		rb(stack_b);
	}
	while (*stack_a)
	{
		if ((*stack_a)->value > max_b)
		{
			max_b = (*stack_a)->value;
			pb(stack_a, stack_b);
		}
		else if ((*stack_a)->value < min_b)
		{
			min_b = (*stack_a)->value;
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
		{
			ra(stack_a);
			while (get_end_value(*stack_a) < max_b)
			{
				pa(stack_a, stack_b);
				max_b = find_max(*stack_b);
			}
			rra(stack_a);
			max_b = (*stack_a)->value;
			pb(stack_a, stack_b);
		}
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

// void sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	if (*stack_a == NULL || is_sorted(*stack_a))
// 		return;

// 	int size = stacksize(*stack_a);

// 	while (!is_sorted(*stack_a))
// 	{
// 		if ((*stack_a)->value == find_min(*stack_a))
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 	}

// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// }

int get_end_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return stack->value;
}

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

int find_max(t_stack *stack)
{
	int max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return max;
}
