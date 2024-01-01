/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:41:50 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/01 19:01:34 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack **stack_b)
{
    swap(stack_b);
    ft_putstr_fd("sb\n", 1);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_putstr_fd("pa\n", 1);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putstr_fd("pb\n", 1);
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}
