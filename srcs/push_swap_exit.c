/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:12:43 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/11 19:31:04 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int ft_check_string(char *list)
// {
//     int i;
//     int last;

//     i = 1;
//     last = ft_strlen(list) - 1;
//     while (i < last)
//     {
//         if (!ft_isalnum(list[i]) || list[i] != " ")
//             return (0);
//         i++;
//     }
//     return (1);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	i = (*s1 - *s2);
	return (i);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
	lst = NULL;
}

//ft_mute