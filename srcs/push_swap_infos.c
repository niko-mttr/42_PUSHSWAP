/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/08 15:30:24 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_index(t_list *stack, int size_list)
{
	t_list	*temp;
	int		index;

	temp = stack;
	while (size_list > 1)
	{
		index = 1;
		index = ft_count_index(temp->value, index, stack);
		size_list--;
		temp->index = index;
		temp = temp->next;
	}
}

void	ft_position(t_list *stack)
{
	int	pos;

	pos = 1;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

int	ft_smallest(t_list *stack, int small, int target, int ref)
{
	while (stack)
	{
		if (stack->index < small && stack->index > ref)
		{
			target = stack->pos;
			small = stack->index;
		}
		stack = stack->next;
	}
	return (target);
}

void	ft_target(t_list *stack_a, t_list *stack_b)
{
	int		size_list;
	int		target;

	size_list = ft_lstsize(stack_a) + ft_lstsize(stack_b);
	while (stack_b)
	{
		target = ft_smallest(stack_a, size_list + 1, -1, stack_b->index);
		if (target == -1)
			target = ft_smallest(stack_a, size_list + 1, -1, 0);
		stack_b->target_pos = target;
		stack_b = stack_b->next;
	}
}

void	ft_cost(t_list *stack_a, t_list *stack_b)
{
	int	trigger_a;
	int	trigger_b;
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_lstsize(stack_a);
	size_stack_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		trigger_a = ft_middle(size_stack_a, stack_b->target_pos);
		trigger_b = ft_middle(size_stack_b, stack_b->pos);
		stack_b->cost_a = ft_calc_cost(size_stack_a, stack_b->target_pos,
				trigger_a);
		stack_b->cost_b = ft_calc_cost(size_stack_b, stack_b->pos, trigger_b);
		stack_b = stack_b->next;
	}
}
