/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler_double.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:21:12 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 19:04:51 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra_and_pa(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	pa(stack_a, stack_b);
}
