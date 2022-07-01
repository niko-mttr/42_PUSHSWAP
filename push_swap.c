/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 17:52:57 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_fillStack(int sizeList, char **list)
{
    int pos;
    int number;
    t_list  *stackA;

    stackA = NULL;
    pos = 1;
    while (pos < sizeList)
    {
        number = ft_atoi(list[pos]);
        if (pos == 1)
            stackA = ft_lstNewNumber(number, pos);
        else
            ft_lstadd_back(&stackA, ft_lstNewNumber(number, pos));
        pos++;
    }
    return (stackA);
}

void    ft_exNumber(int sizeList, char **list)
{
    t_list *stack_test;

    stack_test = ft_fillStack(sizeList, list);
    ft_index(stack_test, sizeList);
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