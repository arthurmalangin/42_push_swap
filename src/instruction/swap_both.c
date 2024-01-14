/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:09:34 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 19:08:10 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_both(t_stack **stack1, t_stack **stack2)
{
	swap(stack1);
	swap(stack2);
	ft_putstr_fd("ss\n", 1);
}
