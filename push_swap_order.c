/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:42:02 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 13:30:42 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int ft_checkOrder(t_list *stack)
{
    int temp;

    temp = stack->value;
    while (stack)
    {
        if (temp > stack->value)
            return 0;
        temp = stack->value;
        stack = stack->next;
    }
    printf("C'est tout bon !!\n");
    return 1;
}