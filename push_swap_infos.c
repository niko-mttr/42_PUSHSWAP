/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 13:30:27 by nicolasmatt      ###   ########.fr       */
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
void	ft_space(t_list *stack_a, t_list *stack_b, int sizeList)
{
	t_list	*temp;
	int	sizeList_a;
	int i;


	sizeList_a = ft_lstsize(stack_a);
	while (stack_b)
	{
		ft_position(stack_a);
		temp = stack_a;
		i = 1;
		while(temp)
		{
			if (temp->index > stack_b->index)
				break ;
			temp = temp->next;
			i++;
		}
		if (i > sizeList_a)
			stack_b->target_pos = 1;
		else
			stack_b->target_pos = i;
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
