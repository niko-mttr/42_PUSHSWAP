/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:16:26 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/06 12:03:46 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_tallest(t_list *stack, int sizeStack)
{
	while (stack->index != sizeStack)
		stack = stack->next;
	return stack->pos;
}

void	ft_finish(t_list **stack)
{
	int	pos;
	int	sizeStack;

	ft_position(*stack);
	sizeStack = ft_lstsize(*stack);
	pos = ft_tallest(*stack, sizeStack);
	if (pos > (sizeStack / 2))
	{
		while (pos < sizeStack)
		{
			ft_reverseRotate(stack);
        	ft_putstr_fd("RRA", 1);
			pos++;
		}
	}
	else
		while (pos)
		{
			ft_rotate(stack);
        	ft_putstr_fd("RA", 1);
			pos--;
		}
}