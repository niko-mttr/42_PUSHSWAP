/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:31:55 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 18:31:59 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_lstNewNumber(int  number, int pos)
{
    t_list  *new;

    new = malloc(sizeof(*new));
    if(!new)
        return (NULL);
    new->value = number;
    new->index = 0;
    new->pos = pos;
    new->target_pos = -1;
    new->cost_a = -1;
    new->cost_b = -1;
    new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst && lst)
	{
		temp = *lst;
		temp = ft_lstlast(temp);
		temp->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

#include <stdio.h>

int	ft_countIndex(int value, int index, t_list *stack)
{
	// printf("la valeur : %d, l'index : %d || la valeur du maillon : %d\n", value, index, stack->value);
	while (stack)
	{
		if (value > stack->value)
			index++;
		stack = stack->next; 
	}
	return (index);
}

void	ft_index(t_list *stack, int sizeList)
{
	int		nb;
	t_list	*temp;
	int		index;

	temp = stack;
	while (sizeList > 1)
	{
		index = 1;
		index = ft_countIndex(temp->value, index, stack);
		printf("la valeur de mon index %d\n", index);
		sizeList--;
		temp->index = index;
		temp = temp->next;
	}
}