/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:16:31 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/02 19:43:21 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_checkex(t_list *chaine)
{
    while (chaine)
    {
        printf("%d ", chaine->value);
        chaine = chaine->next;
    }
    printf("\n");
}