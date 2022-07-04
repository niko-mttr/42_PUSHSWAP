/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:31:55 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/04 09:34:14 by nmattera         ###   ########.fr       */
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
    new->pos = 1;/*pos*/
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

t_list	*ft_lstbeforelast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}
