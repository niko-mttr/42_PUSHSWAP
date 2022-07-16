/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:43:33 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/16 18:30:47 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_index_max(t_list *stack, int indexRef)
{
	while (stack)
	{
		if (stack->index > indexRef)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_index_middle(t_list *stack, int indexRef)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->index > indexRef)
			count++;
		stack = stack->next;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

void	ft_three(t_list **stack)
{
	if (ft_index_max(*stack, (*stack)->next->index))
	{
		ft_reverse_rotate(stack);
		ft_putstr_fd("rra", 1);
	}
	if (ft_index_max(*stack, (*stack)->index))
	{
		ft_rotate(stack);
		ft_putstr_fd("ra", 1);
	}
	if (ft_index_middle(*stack, (*stack)->index))
		ft_swap(stack, "sa");
}
