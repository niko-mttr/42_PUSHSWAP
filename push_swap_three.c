/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:43:33 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/03 21:05:52 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_three(t_list *stack)
{
    if (stack->index == 3)
        ft_rotate(&stack, "RA\n");
    else if (stack->index == 2)
        ft_reverseRotate(&stack, "RRA\n");
    if (stack->index > stack->next->index)
        ft_swap(&stack, "SA\n");
}
    //si l'index du premier est le plus garnd on fait ra
    //sinon si l'index du deuxieme nombre est le lus grand on fait rra
    //ensuite si l'index du premeir nombre > index du deuxieme nombre on fait sa