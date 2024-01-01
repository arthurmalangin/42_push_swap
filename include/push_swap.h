/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:58:33 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/01 20:05:21 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/src/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void    swap(t_stack **stack);
void    push(t_stack **stack1, t_stack **stack2);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    swap_both(t_stack **stack1, t_stack **stack2);
void    rotate_both(t_stack **stack1, t_stack **stack2);
void    reverse_rotate_both(t_stack **stack1, t_stack **stack2);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);

int doublon(char **argv);
int is_sorted(t_stack *stack);
int find_min(t_stack *stack);

#endif