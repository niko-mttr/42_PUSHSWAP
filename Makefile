# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:13:08 by nmattera          #+#    #+#              #
#    Updated: 2022/07/04 12:22:58 by nmattera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT = ./libft

NAME = pushswap.a

SRCS =	push_swap.c push_swap_pars.c \
		push_swap_checkex.c push_swap_stack.c \
		push_swap_actions.c push_swap_infos.c \
		push_swap_order.c push_swap_three.c \
		push_swap_more.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c -I $(LIBFT) $< -o $@

RM = rm -f

$(NAME): $(OBJS)
	cd $(LIBFT) && $(MAKE)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) -r $(OBJS)
	cd $(LIBFT) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBFT) && $(MAKE) fclean

re: fclean all 