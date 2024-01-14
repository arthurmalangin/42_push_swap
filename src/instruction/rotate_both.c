/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:10:59 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 19:07:06 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_both(t_stack **stack1, t_stack **stack2)
{
	rotate(stack1);
	rotate(stack2);
	ft_putstr_fd("rr\n", 1);
}
