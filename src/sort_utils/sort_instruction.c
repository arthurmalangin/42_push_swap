/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:01:32 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/21 02:47:49 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_little_3(t_stack **stack_a)
{
	int	min_a;
	int	max_a;

	while (!is_sorted(*stack_a))
	{
		max_a = find_max(*stack_a);
		min_a = find_min(*stack_a);
		if ((*stack_a)->value == max_a)
		{
			ra(stack_a);
			if (!is_sorted(*stack_a))
				sa(stack_a);
		}
		else if ((*stack_a)->value == min_a)
		{
			ra(stack_a);
		}
		else
		{
			sa(stack_a);
		}
	}
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->value == find_max(*stack_a))
		{
			if ((*stack_b)->value == find_min(*stack_b))
				rotate_both(stack_a, stack_b);
			else
				ra(stack_a);
			if (!is_sorted(*stack_a))
				sa(stack_a);
		}
		else if ((*stack_a)->value == find_min(*stack_a))
		{
			if ((*stack_b)->value == find_min(*stack_b))
				rotate_both(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else
		{
			if (!is_sorted_reverse(*stack_b))
				rb(stack_b);
			sa(stack_a);
		}
	}
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_value;
	int	max_bits;
	int	i;
	int	j;

	max_value = stacksize(*stack_a) - 1;
	max_bits = 0;
	while (max_value >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < stacksize(*stack_a))
		{
			if (((*stack_a)->value >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_final_a(t_stack **stack_a)
{
	while (!is_sorted(*stack_a))
	{
		if (get_end_value(*stack_a) == find_min(*stack_a))
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	sort_set_valid_position(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->value != find_min(*stack_a))
		ra(stack_a);
	pa(stack_a, stack_b);
}
