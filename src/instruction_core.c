/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:50:54 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/01 18:38:46 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    swap(t_stack **stack)
{
    t_stack *tmp;

    if (*stack && (*stack)->next)
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
}

void    push(t_stack **stack1, t_stack **stack2)
{
    t_stack *tmp;

    if (*stack1)
    {
        tmp = *stack1;
        *stack1 = (*stack1)->next;
        tmp->next = *stack2;
        *stack2 = tmp;
    }
}

void    rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (*stack && (*stack)->next)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        tmp2 = *stack;
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
        tmp->next = NULL;
    }
}

void    reverse_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (*stack && (*stack)->next)
    {
        tmp = *stack;
        while (tmp->next->next)
            tmp = tmp->next;
        tmp2 = tmp->next;
        tmp->next = NULL;
        tmp2->next = *stack;
        *stack = tmp2;
    }
}

void    swap_both(t_stack **stack1, t_stack **stack2)
{
    swap(stack1);
    swap(stack2);
    ft_putstr_fd("ss\n", 1);
}

void    rotate_both(t_stack **stack1, t_stack **stack2)
{
    rotate(stack1);
    rotate(stack2);
    ft_putstr_fd("rr\n", 1);
}

void    reverse_rotate_both(t_stack **stack1, t_stack **stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
    ft_putstr_fd("rrr\n", 1);
}
