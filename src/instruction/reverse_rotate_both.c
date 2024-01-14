/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:11:28 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 19:06:43 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_both(t_stack **stack1, t_stack **stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	ft_putstr_fd("rrr\n", 1);
}
