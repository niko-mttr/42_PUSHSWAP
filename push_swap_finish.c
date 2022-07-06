/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:16:26 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/06 12:54:22 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_tallest(t_list *stack, int size_stack)
{
	while (stack->index != size_stack)
		stack = stack->next;
	return (stack->pos);
}

void	ft_finish(t_list **stack)
{
	int	pos;
	int	size_stack;

	ft_position(*stack);
	size_stack = ft_lstsize(*stack);
	pos = ft_tallest(*stack, size_stack);
	if (pos > (size_stack / 2))
	{
		while (pos < size_stack)
		{
			ft_reverse_rotate(stack);
			ft_putstr_fd("RRA", 1);
			pos++;
		}
	}
	else
	{
		while (pos)
		{
			ft_rotate(stack);
			ft_putstr_fd("RA", 1);
			pos--;
		}
	}
}
