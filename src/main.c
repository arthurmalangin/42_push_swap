/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:50:00 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/21 02:47:06 by amalangi         ###   ########.fr       */
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

void display_tab_fd(char **tab, int fd)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd("\n-----START-----\n", fd);
		ft_putstr_fd(tab[i], fd);
		ft_putchar_fd('\n', fd);
		ft_putstr_fd("\n-----END-----\n", fd);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

	//display_tab_fd(argv, open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666));
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack = NULL;
	stack_b = NULL;
	if (!fill_stack(&stack, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!check_param(&stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack);
		return (0);
	}
	if (!simplify_stack(&stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack);
		return (0);
	}
	//display_stack(&stack);
	sort(&stack, &stack_b);
	free_stack(&stack);
	return (0);
}
