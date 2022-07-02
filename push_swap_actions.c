/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:36:42 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/02 19:22:01 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_list **stack)
{
    t_list  *temp;
    t_list  *tail;

    temp = *stack;
    temp->next=NULL;
    *stack = (*stack)->next;
    tail = ft_lstlast(*stack);
    tail->next = temp;
}

void    ft_reverseRotate(t_list **stack)
{
    t_list  *temp;
    t_list  *top;
    t_list  *beforeLast;

    top = ft_lstlast(*stack);
    beforeLast = ft_lstbeforelast(*stack);
    temp = *stack;
    *stack = top;
    top->next = temp;
    beforeLast->next = NULL;
}

void    ft_swap(t_list **stack)
{
    t_list  *newTop;
    t_list  *newTail;
    t_list  *afterTop;
    t_list  *beforeLast;

    newTop = ft_lstlast(*stack);
    beforeLast = ft_lstbeforelast(*stack);
    newTail = *stack;
    afterTop = (*stack)->next;
    *stack = newTop;
    newTop->next = afterTop;
    beforeLast->next = newTail;
    newTail->next = NULL;
}
