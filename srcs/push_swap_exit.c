/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:13:24 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/16 21:08:35 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_malloc_error(t_list	*stack, char **list, int split)
{
	size_t	i;
	t_list	*tmp;

	if (split == 1)
	{
		i = 0;
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
	ft_printf("Pushswap : Malloc failure");
	exit(EXIT_FAILURE);
}

void	ft_end(int split, t_list **stack_a, char **list)
{
	size_t	i;
	t_list	*tmp;

	if (split == 1)
	{
		i = 0;
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		(*stack_a) = tmp;
	}
	free(*stack_a);
}
