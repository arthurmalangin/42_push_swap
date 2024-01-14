/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:46:54 by amalangi          #+#    #+#             */
/*   Updated: 2024/01/14 03:34:37 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stacksize(t_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
int ft_abs(int n)
{
    if (n < 0) {
        return -n;
    } else {
        return n;
    }
}
int get_inferior_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value < value)
			return stack->value;
		stack = stack->next;
	}
	return value;
}

int get_approach_value(t_stack *stack, int value)
{
	int current_difference;
    int closest_value;
    int closest_difference;
	t_stack *tmp;

	tmp = stack;
	closest_value = tmp->value;
    tmp = tmp->next;
	closest_difference = ft_abs(value - closest_value);
    while (tmp)
	{
        current_difference = ft_abs(value - tmp->value);
        if ((current_difference < closest_difference && tmp->value > value) ||
            (current_difference == closest_difference && tmp->value > closest_value)) 
		{
            closest_value = tmp->value;
            closest_difference = current_difference;
        }
        tmp = tmp->next;
    }
    return closest_value;
}

int get_approach_value_inferior(t_stack *stack, int value)
{
    int current_difference;
    int closest_value;
    int closest_difference;
    t_stack *tmp;

    tmp = stack;
    closest_value = INT_MIN;
    closest_difference = INT_MAX;
    while (tmp)
    {
        current_difference = ft_abs(value - tmp->value);
        if ((current_difference < closest_difference && tmp->value < value) ||
            (current_difference == closest_difference && tmp->value < closest_value && tmp->value < value)) 
        {
            closest_value = tmp->value;
            closest_difference = current_difference;
        }
        tmp = tmp->next;
    }
    return closest_value;
}


int get_index(t_stack *stack, int value)
{
	int i = 1;
	while (stack)
	{
		if (stack->value == value)
			return i;
		stack = stack->next;
		i++;
	}
	return 0;
}

void sort_stack_a_3(t_stack **stack_a)
{
	int min_a;
	int max_a;

	while (!is_sorted(*stack_a))
	{
		max_a = find_max(*stack_a);
		min_a = find_min(*stack_a);
		if ((*stack_a)->value == max_a)
		{
			ra(stack_a);
			if (!is_sorted(*stack_a))
				sa(stack_a);
		}
		else if ((*stack_a)->value == min_a)
		{
			ra(stack_a);
		}
		else
		{
			sa(stack_a);
		}
	}
}

void sort_stack_a_3_5(t_stack **stack_a, t_stack **stack_b)
{
	int min_a;
	int max_a;

	while (!is_sorted(*stack_a))
	{
		max_a = find_max(*stack_a);
		min_a = find_min(*stack_a);
		if ((*stack_a)->value == max_a)
		{
			if ((*stack_b)->value == find_min(*stack_b))
				rotate_both(stack_a, stack_b);
			else
				ra(stack_a);
			if (!is_sorted(*stack_a))
				sa(stack_a);
		}
		else if ((*stack_a)->value == min_a)
		{
			if ((*stack_b)->value == find_min(*stack_b))
				rotate_both(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else
		{
			if (!is_sorted_reverse(*stack_b))
				rb(stack_b);
			sa(stack_a);
		}
	}
}

void sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int max_value;
	int max_bits;
	int i;
	int j;

	size = stacksize(*stack_a);
	max_value = size - 1;
	max_bits = 0;
	while ((max_value >> max_bits) != 0) // TODO SIMPLIFY IF WORK
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->value >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
	
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || is_sorted(*stack_a))
		return;
	int min_b;
	int max_b;
	int min_a;
	int max_a;

	if (stacksize(*stack_a) == 3)
	{
		sort_stack_a_3(stack_a);
		return;
	}
	if (stacksize(*stack_a) == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		min_b = find_min(*stack_b);
		max_b = find_max(*stack_b);
		sort_stack_a_3_5(stack_a, stack_b);
		while (*stack_b)
		{
			//ft_printf("approach value of %d is %d\n", (*stack_b)->value, get_approach_value(*stack_a, (*stack_b)->value));
			if (get_approach_value(*stack_a, (*stack_b)->value) == (*stack_a)->value && (*stack_b)->value < find_max(*stack_a))
			{
				pa(stack_a, stack_b);
			}
			else if ((*stack_b)->value > find_max(*stack_a))
			{
				while ((*stack_a)->value != find_min(*stack_a))
					ra(stack_a);
				pa(stack_a, stack_b);	
			}
			else
			{

				if (get_approach_value(*stack_a, (*stack_b)->value) == get_end_value(*stack_a))
				{
					rra(stack_a);
					pa(stack_a, stack_b);
				}
				else
					ra(stack_a);
			}
		}
		while (!is_sorted(*stack_a))
			if (get_end_value(*stack_a) == find_min(*stack_a))
				rra(stack_a);
			else
				ra(stack_a);
	}
	else
	{
		sort_radix(stack_a, stack_b);
		// if ((*stack_b )->value == min_b)
		// 	rb(stack_b);
		// while ((*stack_a))
		// {
		// 	if ((*stack_a)->value > find_min(*stack_b) && (*stack_a)->value < find_max(*stack_b))
		// 	{
		// 		//ft_printf("approach value of %d is %d\n", (*stack_a)->value, get_approach_value_inferior(*stack_b, (*stack_a)->value));
		// 		if ((*stack_b)->value == get_approach_value_inferior(*stack_b, (*stack_a)->value))
		// 			pb(stack_a, stack_b);
		// 		else
		// 		{
		// 			while (!((*stack_b)->value == get_approach_value_inferior(*stack_b, (*stack_a)->value)))
		// 			{
		// 				if (get_index(*stack_b, get_approach_value_inferior(*stack_b, (*stack_a)->value)) <= stacksize(*stack_b) / 2)
		// 					rb(stack_b);
		// 				else
		// 					rrb(stack_b);
		// 			}
		// 		}
		// 	}
		// 	// else if ((*stack_a)->value < find_min(*stack_b))
		// 	// {
		// 	// 	//ft_printf("min\n");
		// 	// 	while ((*stack_b)->value != find_max(*stack_b))
		// 	// 	{
		// 	// 		if (get_index(*stack_b, find_max(*stack_b)) <= stacksize(*stack_b) / 2)
		// 	// 			rb(stack_b);
		// 	// 		else
		// 	// 			rrb(stack_b);
		// 	// 	}
		// 	// 	pb(stack_a, stack_b);
		// 	// }
		// 	else
		// 	{
		// 		//ft_printf("max\n");
		// 		while ((*stack_b)->value != find_max(*stack_b))
		// 		{
		// 			if (get_index(*stack_b, find_max(*stack_b)) <= stacksize(*stack_b) / 2)
		// 				rb(stack_b);
		// 			else
		// 				rrb(stack_b);
		// 		}
		// 		pb(stack_a, stack_b);
		// 	}
		// 	//ft_printf("loop\n");
		// }
		// while ((*stack_b)->value != find_max(*stack_b))
		// {
		// 	if (get_index(*stack_b, find_max(*stack_b)) <= stacksize(*stack_b) / 2)
		// 		rb(stack_b);
		// 	else
		// 		rrb(stack_b);
		// }
		// while (*stack_b)
		// 	pa(stack_a, stack_b);
	}
}

int get_end_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return stack->value;
}

int find_min(t_stack *stack)
{
	int min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return min;
}

int find_max(t_stack *stack)
{
	int max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return max;
}
