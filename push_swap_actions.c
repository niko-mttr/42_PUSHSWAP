/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:36:42 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 10:07:08 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_list **stack, char *instruction)
{
    t_list  *temp;
    t_list  *tail;

    temp = *stack;
    *stack = (*stack)->next;
    tail = ft_lstlast(*stack);
    temp->next=NULL;
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
