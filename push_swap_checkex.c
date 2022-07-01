/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:16:31 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 18:12:32 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_checkex(t_list *chaine)
{
    while (chaine)
    {
        printf("la valeur : %d || l'index %d\n", chaine->value, chaine->index);
        chaine = chaine->next;
    }
}