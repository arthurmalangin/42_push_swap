/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:06:49 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 19:06:26 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (*stack1)
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		tmp->next = *stack2;
		*stack2 = tmp;
	}
}
