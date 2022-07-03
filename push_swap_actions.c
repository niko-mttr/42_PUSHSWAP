/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:36:42 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/03 21:05:36 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_list **stack, char *instruction)
{
    t_list  *temp;
    t_list  *tail;

    temp = *stack;
    temp->next=NULL;
    *stack = (*stack)->next;
    tail = ft_lstlast(*stack);
    tail->next = temp;
    ft_putstr_fd(instruction, 1);
}

void    ft_reverseRotate(t_list **stack, char *instruction)
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
    ft_putstr_fd(instruction, 1);
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
