/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/06 11:17:15 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_index(t_list *stack, int sizeList)
{
	int		nb;
	t_list	*temp;
	int		index;

	temp = stack;
	while (sizeList > 1)
	{
		index = 1;
		index = ft_countIndex(temp->value, index, stack);
		sizeList--;
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
	while(stack)
	{
		if (stack->index < small && stack->index > ref)
		{
			target = stack->pos;
			small = stack->index;
		}
		stack = stack->next;
	}
	return target;

}

void	ft_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	int	sizeList;
	int	small;
	int	target;

	sizeList = ft_lstsize(stack_a) + ft_lstsize(stack_b);
	while (stack_b)
	{
		temp = stack_a;
		small = -1;
		target = 1;
		target = ft_smallest(stack_a, sizeList + 1 , -1, stack_b->index);
		if (target == -1)
			target = ft_smallest(stack_a, sizeList + 1, -1, 0);
		stack_b->target_pos = target;
		stack_b = stack_b->next;
	}
}

void	ft_cost(t_list *stack_a, t_list *stack_b)
{
	int	trigger_a;
	int	trigger_b;
	int	sizeStack_a;
	int	sizeStack_b;

	sizeStack_a = ft_lstsize(stack_a);
	sizeStack_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		trigger_a = ft_middle(sizeStack_a, stack_b->target_pos);
		trigger_b = ft_middle(sizeStack_b, stack_b->pos);
		stack_b->cost_a = ft_calcCost(sizeStack_a, stack_b->target_pos, trigger_a);
		stack_b->cost_b = ft_calcCost(sizeStack_b, stack_b->pos, trigger_b);
		stack_b = stack_b->next;
	}
}
