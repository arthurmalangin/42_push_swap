/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:46:54 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/21 02:48:06 by amalangi         ###   ########.fr       */
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

void	sort_init_little(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_stack_a(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (stacksize(*stack_a) == 3)
		sort_little_3(stack_a);
	else if (stacksize(*stack_a) == 5)
	{
		sort_init_little(stack_a, stack_b);
		while (*stack_b)
		{
			if (get_approach_value(*stack_a, (*stack_b)->value)
				== (*stack_a)->value && (*stack_b)->value < find_max(*stack_a))
				pa(stack_a, stack_b);
			else if ((*stack_b)->value > find_max(*stack_a))
				sort_set_valid_position(stack_a, stack_b);
			else
			{
				if (get_approach_value(*stack_a, (*stack_b)->value)
					== get_end_value(*stack_a))
					rra_and_pa(stack_a, stack_b);
				else
					ra(stack_a);
			}
		}
		sort_final_a(stack_a);
	}
	else
		sort_radix(stack_a, stack_b);
}
