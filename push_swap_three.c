/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:43:33 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 11:16:22 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    ft_three(t_list **stack)
{
    if ((*stack)->next->index == 3)
        ft_reverseRotate(stack, "RRA\n");
    if ((*stack)->index == 3)
        ft_rotate(stack, "RA\n");
    if ((*stack)->index == 2)
        ft_swap(stack, "SA\n");
}
