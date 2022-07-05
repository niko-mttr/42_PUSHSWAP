/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:40:46 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 11:54:23 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int ft_middle(int sizeStack, int pos)
{
    int trigger;

    trigger = 1;
    if (pos > sizeStack / 2)
        trigger = -1;
    return trigger;
}

int ft_calcCost(int sizeStack, int pos, int trigger)
{
    
}