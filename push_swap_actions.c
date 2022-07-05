/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:36:42 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 20:23:44 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_list **stack)
{
    t_list  *temp;
    t_list  *tail;

    temp = *stack;
    *stack = (*stack)->next;
    tail = ft_lstlast(*stack);
    temp->next=NULL;
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

void    ft_swap(t_list **stack, char *instruction)
{
    int	tmp;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
    ft_putstr_fd(instruction, 1);
}

void    ft_push(t_list **src, t_list **dest)
{
    t_list *transfer;
    t_list *destewTop;
    

    transfer = *src;
    *src = (*src)->next;
    ft_lstadd_front(dest, transfer);
    // est ce que je dois free mon transfer dans ma src
}
#include <stdio.h>

void    ft_callAction(t_list **stack_a, t_list **stack_b, char *call)
{
    if (!ft_strcmp(call, "PB"))
        ft_push(stack_a, stack_b);
    if (!ft_strcmp(call, "PA"))
        ft_push(stack_b, stack_a);
    if (!ft_strcmp(call, "RA"))
    {
        ft_rotate(stack_a);
    }
    if (!ft_strcmp(call, "RB"))
        ft_rotate(stack_b);
    if (!ft_strcmp(call, "RRA"))
        ft_reverseRotate(stack_a);
    if (!ft_strcmp(call, "RRB"))
        ft_reverseRotate(stack_b);
    if (!ft_strcmp(call, "RR"))
    {
        ft_rotate(stack_a);
        ft_rotate(stack_b);
    }
    if (!ft_strcmp(call, "RRR"))
    {
        ft_reverseRotate(stack_a);
        ft_reverseRotate(stack_b);
    }
    ft_putstr_fd(call, 1);
}