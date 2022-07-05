/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:42:01 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 13:30:34 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//combien ça coute d'amener l'élément au sommet de la pile B ? De même pour l'élément cible de la pile A ?
    // soit un rotate : déplace l'élément au sommet en bas
    // soit un reverseRotate : déplace l'élément en bas au sommet
        // -> il faut calculer et chosir la méthode la moins couteuse
            //obetnir le milieu de la pile (longeur de la pile / 2)
                // chosir entre rotate et reverse rotate
                    //if pos grand que le milieu = reverse rotate (*cout négatif)
                    //else pos petite que le milieu = rotate
                //calculer le nombre de cout = disatnce 
                    // ->différence reverse rotate :
                    // ->différence rotate :
    // si les deux éléments ont le même signe on pourra faire un RR, ou RRR