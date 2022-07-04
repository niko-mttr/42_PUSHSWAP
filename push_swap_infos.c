/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 19:30:40 by nmattera         ###   ########.fr       */
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
	int	sizeList_a;
	int i;


	sizeList_a = ft_lstsize(stack_a);
	printf("la taille de ma liste : %d\n", sizeList_a);
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
