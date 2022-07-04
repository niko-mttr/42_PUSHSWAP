/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 18:45:17 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_countIndex(int value, int index, t_list *stack)
{
	while (stack)
	{
		if (value > stack->value)
			index++;
		stack = stack->next; 
	}
	return (index);
}

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
	int i;

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
		stack_b->target_pos = i;
		stack_b = stack_b->next;
	}
}

void	ft_target_pos(t_list *stack_a, t_list *stack_b)
{
	int space;
	int	target_pos;
	t_list	*temp1;
	t_list	*temp2;
	

	while (stack_b)
	{
		temp1 = stack_a;
		temp2 = stack_a;
		while (temp1->value < stack_b->value)
			temp1 = temp1->next;
		space = temp1->value - stack_b->value;
		stack_b->target_pos = temp1->pos;
		while (temp2)
		{
			if (temp2->value - stack_b->value < space)
			{
				printf("je passe la !!!\n");
				space = temp2->value - stack_b->value;
				stack_b->target_pos = temp2->pos;
			}
			temp2 = temp2->next;
		}

		stack_b = stack_b->next;
	}
}

