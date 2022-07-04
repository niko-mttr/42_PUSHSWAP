/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:47 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 19:24:55 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list  *ft_lstNewNumber(int  number, int pos)
{
    t_list  *new;

    new = malloc(sizeof(*new));
    if(!new)
        return (NULL);
    new->value = number;
    new->index = 0;
    new->pos = 1;
    new->target_pos = -1;
    new->cost_a = -1;
    new->cost_b = -1;
    new->next = NULL;
	return (new);
}

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
    t_list  *stack_a;
    t_list  *stack_b;

    stack_b = malloc(sizeof(*stack_b));
    stack_b = NULL;
    stack_a = ft_fillStack(sizeList, list);
    ft_index(stack_a, sizeList);
    ft_position(stack_a);
    if (!ft_checkOrder(stack_a))
    {
        if (sizeList - 1 == 2)
           ft_swap(&stack_a, "SA\n");
        else if (sizeList - 1 == 3)
            ft_three(&stack_a);
        else if (sizeList - 1 > 3)
            ft_more(&stack_a, &stack_b, sizeList - 1);
    }
    ft_checkex(stack_a, "-----stack_a-----\n");
    ft_checkex(stack_b, "-----stack_b-----\n");
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