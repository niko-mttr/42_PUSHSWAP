/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:26:57 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/16 20:22:18 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_over(int split, t_list **stack, char **list)
{
	ft_putstr_fd("Error\n", 1);
	ft_end(split, stack, list);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *nptr, t_list **stack, int split, char **list)
{
	long	res;
	int		minus;
	int		i;

	i = 0;
	res = 0;
	minus = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && i < 12)
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if (res * minus < -2147483648 || res * minus > 2147483647)
		ft_over(split, stack, list);
	return ((int)(res * minus));
}
