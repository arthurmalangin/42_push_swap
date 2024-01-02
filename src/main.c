/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:50:00 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/02 15:30:38 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *new_stack(int value)
{
    t_stack *stack;

    if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
        return (NULL);
    stack->value = value;
    stack->next = NULL;
    return (stack);
}

void add_stack(t_stack **stack, int value)
{
    t_stack *new;
    t_stack *tmp;

    new = new_stack(value);
    if (!*stack) {
        *stack = new;
    } else {
        tmp = *stack;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void display_stack(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp)
    {
        ft_printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

void fill_stack(t_stack **stack, char **argv, int i)
{
    while (argv[i])
    {
        add_stack(stack, ft_atoi(argv[i]));
        i++;
    }
}

int is_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);    
}

int is_sorted_reverse(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->value < stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);    
}

int check_param(char **argv)
{
    int i;
    int j;

    i = 1;
    // while (argv[i])
    // {
    //     j = 0;
    //     while (argv[i][j])
    //     {
    //         if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
    //             return (0);
    //         if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
    //             return (0);
    //         j++;
    //     }
    //     i++;
    // }
    if (!doublon(argv))
        return (0);
    return (1);
}

int doublon(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    sort(t_stack **stack_a, t_stack **stack_b);

int main(int argc, char **argv)
{
    t_stack *stack;
    t_stack *stack_b;
    
    stack = NULL;
    stack_b = NULL;
    if (!check_param(argv))
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    if (argc == 2)
        fill_stack(&stack, ft_split(argv[1], ' '), 0);
    else
        fill_stack(&stack, argv, 1);
    sort(&stack, &stack_b);
    return (0);
}