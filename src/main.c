/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:50:00 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/25 17:42:52 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack = NULL;
	stack_b = NULL;
	if (!fill_stack(&stack, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!stack || !check_param(&stack) || !simplify_stack(&stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack);
		return (0);
	}
	if (!is_sorted(stack))
		sort(&stack, &stack_b);
	free_stack(&stack);
	return (0);
}
