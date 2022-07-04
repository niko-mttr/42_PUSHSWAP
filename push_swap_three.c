/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:43:33 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 16:08:30 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int ft_index_max(t_list *stack, int indexRef)
{
    while (stack)
    {
        if (stack->index > indexRef)
            return 0;
        stack = stack->next;
    }
    return 1;
}

static int ft_index_middle(t_list *stack, int indexRef)
{
    int count;

    count = 0;
     while (stack)
    {
        if (stack->index > indexRef)
            count++;
        stack = stack->next;
    }
    if (count == 1)
        return 1;
    else
        return 0;
}

void    ft_three(t_list **stack)
{
    if (ft_index_max(*stack, (*stack)->next->index))
        ft_reverseRotate(stack, "RRA\n");
    if (ft_index_max(*stack ,(*stack)->index))
        ft_rotate(stack, "RA\n");
    if ((*stack)->index == 2/*mon index du milieu*/)
        ft_swap(stack, "SA\n");
}
