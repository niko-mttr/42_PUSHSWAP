/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 10:53:24 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list *ft_fillStack(int sizeList, char **list)
{
    int pos;
    int number;
    t_list  *stack;

    stack = NULL;
    pos = 1;
    while (pos < sizeList)
    {
        number = ft_atoi(list[pos]);
        if (pos == 1)
            stack = ft_lstNewNumber(number, pos);
        else
            ft_lstadd_back(&stack, ft_lstNewNumber(number, pos));
        pos++;
    }
    return (stack);
}

void    ft_exNumber(int sizeList, char **list)
{
    t_list *stack_test;

    stack_test = ft_fillStack(sizeList, list);
    ft_index(stack_test, sizeList);
    ft_position(stack_test);
    if (!ft_checkOrder(stack_test))
    {
        if (sizeList - 1 == 2)
           ft_swap(&stack_test, "SA\n");
        else if (sizeList - 1 == 3)
            ft_three(&stack_test);
        // else
        //     ft_algo();
    }
    ft_checkex(stack_test);
}

int main(int argc, char **argv)
{
    if (argc == 0 || argc == 1)
        return 0;
    if (ft_parsNumber(argc, argv))
        ft_exNumber(argc, argv);
}

//value : valeur du nombre
//index : son index dans toute la liste des valeurs à trier
//pos : sa position actuelle dans sa stack
//target_pos : la position où il devrait se trouver dans la pile A
// cost_a : combien d’actions cela coûterait de faire pivoter la pile A pour que l’élément à la position ciblée arrive au sommet de la pile A,
// cost_b : combien d’actions cela coûterait de faire pivoter la pile B pour que cet élément arrive au sommet de la pile B,