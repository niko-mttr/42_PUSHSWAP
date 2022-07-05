/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:40:46 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 13:30:31 by nicolasmatt      ###   ########.fr       */
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
    int cost;

    if (trigger > 0)
        cost = pos - 1;
    else
        cost = sizeStack - pos + 1;
    return (cost * trigger);
}
    //reverse rotate : donc c'est l'écart entre la position et la taille + 1;
    //rotate : donc c'est l'écart entre la position et 1;

int ft_absolute(int number)
{
    if (number < 0)
        number *= -1;
    return number;
}