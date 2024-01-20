/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 04:43:19 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/15 04:52:10 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*join_free(char *s1, char *s2)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(s1, " ");
	tmp = str;
	str = ft_strjoin(str, s2);
	free(s1);
	free(tmp);
	return (str);
}
