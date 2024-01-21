/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:19:42 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/21 17:29:37 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	add_stack(t_stack **stack, size_t value)
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

int	contain_char(char *str, char c)
{
	int	i;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	fill_stack_tabs(t_stack **stack, char *ptr)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(ptr, ' ');
	while (tab[i])
	{
		if (ft_atoll(tab[i]) > INT_MAX || ft_atoll(tab[i])
			< INT_MIN || contain_alpha(tab[i]))
		{
			free(ptr);
			free_tab(tab);
			return (0);
		}
		add_stack(stack, ft_atoll(tab[i]));
		i++;
	}
	free(ptr);
	free_tab(tab);
	return (1);
}

int	fill_stack(t_stack **stack, char **argv)
{
	int		i;
	char	*ptr;
	char	*space;

	ptr = NULL;
	i = 1;
	if (contain_empty_arg(argv))
		return (0);
	while (argv[i])
	{
		if (!ptr)
		{
			ptr = malloc(sizeof(char) * (ft_strlen(argv[i]) + 1));
			ft_strlcpy(ptr, argv[i], ft_strlen(argv[i]) + 1);
		}
		else
			ptr = join_free(ptr, argv[i]);
		i++;
	}
	if (!fill_stack_tabs(stack, ptr))
		return (0);
	return (1);
}
