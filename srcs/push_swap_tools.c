/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:12:43 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/11 11:17:53 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_check_string(char *list)
{
    int i;
    int last;

    i = 1;
    last = ft_strlen(list) - 1;
    while (i < last)
    {
        if (!ft_isalnum(list[i]) || list[i] != " ")
            return (0);
        i++;
    }
    return (1);
}