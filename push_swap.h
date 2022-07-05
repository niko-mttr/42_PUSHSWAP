/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:58:36 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/07/05 14:32:14 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
    int     value;
    int     index;
    int     pos;
    int     target_pos;
    int     cost_a;
    int     cost_b;
    void    *content;
    struct s_list  *next;
}               t_list;

/* ****** push_swap.c ****** */
t_list  *ft_lstNewNumber(int  number, int pos);
t_list *ft_fillStack(int sizeList, char **list);
void    ft_exNumber(int sizeList, char **list);
int main(int argc, char **argv);

/* ******* push_swap_pars ****** */
int ft_parsNumber(int   sizeList, char **list);
int ft_is_num(char c);
int ft_doublon(int sizeList, char **list, int check);
int	ft_strcmp(char *s1, char *s2);

/* ******* push_swap_checkex ******* */
void ft_checkex(t_list *chaine, char *name);

/* ******* push_swap_stack ****** */
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	    ft_lstsize(t_list *lst);

/* ****** push_swap_infos ****** */
void	ft_index(t_list *stack, int sizeList);
void	ft_position(t_list *stack);
void	ft_space(t_list *stack_a, t_list *stack_b, int sizeList);
void	ft_cost(t_list *stack_a, t_list *stack_b);

/* ****** push_swap_actions ****** */
void    ft_rotate(t_list **stack);
void    ft_reverseRotate(t_list **stack);
void    ft_swap(t_list **stack);
void    ft_push(t_list **stack_a, t_list **stack_b);
void    ft_callAction(t_list **stack_a, t_list **stack_b, char *call);

/* ****** push_swap_utils.c ****** */
int 	ft_countIndex(int value, int index, t_list *stack);
int     ft_middle(int sizeStack, int pos);
int     ft_calcCost(int sizeStack, int pos, int trigger);
int     abs(int number);
t_list  *ft_chooseStack(t_list *sk);

/* ****** push_swap_order.c ****** */
int     ft_checkOrder(t_list *stack);

/* ****** push_swap_three.c ****** */
static int ft_index_max(t_list *stack, int indexRef);
static int ft_index_middle(t_list *stack, int indexRef);
void    ft_three(t_list **stack);

/* ****** push_swap_more.c ****** */
void	ft_more(t_list **stack_a, t_list **stack_b, int sizeList);

#endif