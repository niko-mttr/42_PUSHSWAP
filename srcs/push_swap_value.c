/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:26:57 by nmattera          #+#    #+#             */
/*   Updated: 2022/07/14 11:56:00 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *nptr, t_list **stack)
{
	long	res;
	int	minus;
	int	i;

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
	{
		ft_printf("INT OVERFLOW\n");
		ft_delstack(stack);
		exit(EXIT_FAILURE);
	}
	return ((int)(res * minus));
}
