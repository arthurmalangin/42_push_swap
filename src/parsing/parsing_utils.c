/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:05:05 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/21 17:28:36 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long long int	ft_atoll(const char *str)
{
	int				negative;
	int				i;
	long long int	nb;

	i = 0;
	negative = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = negative * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * negative);
}

int	contain_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	contain_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
