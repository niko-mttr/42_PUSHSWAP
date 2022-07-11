# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 15:23:20 by nicolasmatt       #+#    #+#              #
#    Updated: 2022/07/11 12:23:12 by nicolasmatt      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap
NAME_BONUS = pushswap_bonus

SRCS = srcs/push_swap_actions.c srcs/push_swap_checkex.c srcs/push_swap_finish.c srcs/push_swap_infos.c srcs/push_swap_more.c srcs/push_swap_order.c srcs/push_swap_pars.c srcs/push_swap_stack.c srcs/push_swap_three.c srcs/push_swap_utils.c srcs/push_swap.c srcs/push_swap_tools.c
SRCSB = srcsb/push_swap.c

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}

cc = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I libft -I includes

.c.o: @${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJS}
	@echo "----Compiling lib----"
	@make re -C libft --no-print-directory
	@echo "Push Swap Compiled!"

${NAME_BONUS}: ${OBJS}
	@echo "----Compiling lib----"
	@make re -C libft --no-print-directory

clean:
	@make clean -C libft --no-print-directory
	@rm -f ${OBJS}
	@rm -f ${OBJSB}

fclean: clean
	@make fclean -C libft
	@rm -f ${NAME}
	@rm -f $(NAME_BONUS)
	@echo "Deleting EVERYTHING!\n"

re: fclean all

bonus: ${NAME_BONUS}

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus