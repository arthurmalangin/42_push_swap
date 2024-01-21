/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:58:33 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/20 06:38:49 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/src/libft.h"
# include <limits.h>
# include <stdarg.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				size;
	int				value;
	struct s_stack	*next;
}	t_stack;

void	swap(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap_both(t_stack **stack1, t_stack **stack2);
void	rotate_both(t_stack **stack1, t_stack **stack2);
void	reverse_rotate_both(t_stack **stack1, t_stack **stack2);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rra_and_pa(t_stack **stack_a, t_stack **stack_b);
int		doublon(char **argv);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		get_approach_value(t_stack *stack, int value);
int		get_end_value(t_stack *stack);
void	display_stack(t_stack **stack);
int		is_sorted_reverse(t_stack *stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		simplify_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);
void	sort_stack_a(t_stack **stack_a, t_stack **stack_b);
void	sort_little_3(t_stack **stack_a);
void	sort_radix(t_stack **stack_a, t_stack **stack_b);
void	sort_final_a(t_stack **stack_a);
void	sort_set_valid_position(t_stack **stack_a, t_stack **stack_b);
int		stacksize(t_stack *lst);
int		check_param(t_stack **stack);
int		doublon(char **argv);
int		fill_stack(t_stack **stack, char **argv);
void	free_stack(t_stack **stack);
void	free_tab(char **tab);
char	*join_free(char *s1, char *s2);
long long int	ft_atoll(const char *str);
int		contain_alpha(char *str);	
int		contain_empty_arg(char **argv);
#endif