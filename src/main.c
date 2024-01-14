/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:50:00 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 18:57:20 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	add_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = new_stack(value);
	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	fill_stack(t_stack **stack, char **argv, int i)
{
	while (argv[i])
	{
		add_stack(stack, ft_atoi(argv[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

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
	simplify_stack(&stack);
	sort(&stack, &stack_b);
	return (0);
}
